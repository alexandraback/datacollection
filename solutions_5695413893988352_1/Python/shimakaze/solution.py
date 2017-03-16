from collections import Counter

def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    string = f.readline().strip()
    ans = ''
    print "Doing case %d: " % (nt+1)
    scores = string.split(' ')

    best_solution = get_best_solution(scores)
    print best_solution

    o.write("Case #%d: %s %s\n" % ((nt+1), best_solution[0], best_solution[1]))

def get_best_solution(scores):
    index = 0
    best_sol = (-1, -1, float('inf'))
    easy_break = False

    # base case: finished
    if '?' not in scores[0] and '?' not in scores[1]:
        print "Got: %s v %s" % (scores[0], scores[1])
        coders = scores[0]
        others = scores[1]
        return (coders, others, abs(int(coders) - int(others)))

    while index < len(scores[0]):
        if scores[0][index] != '?' and scores[1][index] != '?' and scores[0][index] != scores[1][index]:
            easy_break = True
            break
        if scores[0][index] == '?' or scores[1][index] == '?':
            break
        index += 1

    # base case: one is clearly higher than the other
    if easy_break:
        best00 = get_best_solution([replace_all(scores[0], index, scores[0][index], '0'), replace_all(scores[1], index, scores[1][index], '9')])
        best01 = get_best_solution([replace_all(scores[0], index, scores[0][index], '9'), replace_all(scores[1], index, scores[1][index], '0')])
        possibilities = [best00, best01]

    # if both ?, try 3 possibilities: 1/0, 0/1 and 0/0
    if not easy_break:
        if scores[0][index] == '?' and scores[1][index] == '?':
            best00 = get_best_solution([replace(scores[0], index, '0'), replace(scores[1], index, '0')])
            best01 = get_best_solution([replace_all(scores[0], index, '0', '9'), replace_all(scores[1], index, '1', '0')])
            best10 = get_best_solution([replace_all(scores[0], index, '1', '0'), replace_all(scores[1], index, '0', '9')])
            best09 = get_best_solution([replace_all(scores[0], index, '0', '0'), replace_all(scores[1], index, '9', '9')])
            best90 = get_best_solution([replace_all(scores[0], index, '9', '9'), replace_all(scores[1], index, '0', '0')])
            possibilities = [best00, best01, best10, best09, best90]
        elif scores[0][index] == '?':
            numFilled = scores[1][index]

            numUp = str((int(numFilled) + 1) % 10)
            numDown = str((int(numFilled) - 1) % 10)

            best00 = get_best_solution([replace(scores[0], index, numFilled), replace(scores[1], index, numFilled)])
            best01 = get_best_solution([replace_all(scores[0], index, numUp, '0'), replace_all(scores[1], index, numFilled, '9')])
            best10 = get_best_solution([replace_all(scores[0], index, numDown, '9'), replace_all(scores[1], index, numFilled, '0')])

            possibilities = [best00, best01, best10]
        else:
            numFilled = scores[0][index]

            numUp = str((int(numFilled) + 1) % 10)
            numDown = str((int(numFilled) - 1) % 10)

            best00 = get_best_solution([replace(scores[0], index, numFilled), replace(scores[1], index, numFilled)])
            best01 = get_best_solution([replace_all(scores[0], index, numFilled, '0'), replace_all(scores[1], index, numDown, '9')])
            best10 = get_best_solution([replace_all(scores[0], index, numFilled, '9'), replace_all(scores[1], index, numUp, '0')])

            possibilities = [best00, best01, best10]

    for i in xrange(len(possibilities)):
        if possibilities[i][2] < best_sol[2]:
            best_sol = possibilities[i]
        elif possibilities[i][2] == best_sol[2]:
            if possibilities[i][0] < best_sol[0]:
                best_sol = possibilities[i]
            elif possibilities[i][0] == best_sol[0]:
                if possibilities[i][1] < best_sol[1]:
                    best_sol = possibilities[i]

    return best_sol

def replace(string, index, char):
    f = list(string)
    f[index] = char
    return ''.join(f)

def replace_all(string, index, char, subchar):
    f = list(string)
    if f[index] != '?' and f[index] != char:
        raise Exception
    f[index] = char
    for i in xrange(index + 1, len(f)):
        if f[i] == '?':
            f[i] = subchar
    return ''.join(f)

solve('B-large.in')

NUMBERS = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def match(x, X):
    x = '0' * (len(X) - len(x)) + x
    for l1, l2 in zip(x, X):
        if l2 != '?' and l1 != l2:
            return False
    return True

def replace(string, index, num):
    assert string[index] == '?'
    return string[:index] + str(num) + string[index+1:]

def fmt(num, length):
    num = str(num)
    return '0' * (length - len(num)) + num

def maximize(X):
    return X.replace('?', '9')

def minimize(X):
    return X.replace('?', '0')

def answer(C, J):
    c_first, j_first = C.find('?'), J.find('?')
    try:
        minimum = min(x for x in [c_first, j_first] if x != -1)
    except:
        minimum = None

    if minimum is not None:
        if C[:minimum] > J[:minimum]:
            return minimize(C), maximize(J)
        elif C[:minimum] < J[:minimum]:
            return maximize(C), minimize(J)

    if C.find('?') in [len(C) - 1, -1] and J.find('?') in [len(C) - 1, -1]:
        if len(C) == len(J) == 1:
            if C[0] == '?' and J[0] == '?':
                return '0', '0'
            if C[0] == '?':
                return J, J
            elif J[0] == '?':
                return C, C
            else:
                return C, J
        if C[-1] == J[-1] == '?':
            if C[-2] > J[-2]:
                return replace(C, len(C) - 1, 0), replace(J, len(J) - 1, 9)
            elif C[-2] < J[-2]:
                return replace(C, len(C) - 1, 9), replace(J, len(J) - 1, 0)
            else:
                return replace(C, len(C) - 1, 0), replace(J, len(J) - 1, 0)
        elif C[-1] == '?':
            if C[-2] > J[-2]:
                return replace(C, len(C) - 1, 0), J
            elif C[-2] < J[-2]:
                return replace(C, len(C) - 1, 9), J
            else:
                return replace(C, len(C) - 1, J[-1]), J
        elif J[-1] == '?':
            if C[-2] > J[-2]:
                return C, replace(J, len(J) - 1, 9)
            elif C[-2] < J[-2]:
                return C, replace(J, len(J) - 1, 0)
            else:
                return C, replace(J, len(J) - 1, C[-1])
        else:
            return C, J

    # print 'DOWN HERE'
    i = minimum
    poss = []
    if C[i] == '?' and J[i] == '?':
        if C[i+1] == '?' and J[i+1] == '?':
            return answer(replace(C, i, 0), replace(J, i, 0))
        poss.append((replace(C, i, 0), replace(J, i, 0)))
        poss.append((replace(C, i, 0), replace(J, i, 1)))
        poss.append((replace(C, i, 1), replace(J, i, 0)))
        # print 'POSS 0', poss
    elif C[i] == '?':
        j = J[i]
        numbers = [x for x in [int(j), int(j)+1, int(j)-1] if x >= 0 and x <= 9]
        poss = [(replace(C, i, x), J) for x in numbers]
        # print 'POSS 1', poss
    elif J[i] == '?':
        c = C[i]
        numbers = [x for x in [int(c), int(c)+1, int(c)-1] if x >= 0 and x <= 9]
        poss = [(C, replace(J, i, x)) for x in numbers]
        # print 'POSS 2', poss
    best_c, best_j = None, None
    for poss_c, poss_j in poss:
        # print 'TRYING OUT', poss_c, poss_j, best_c, best_j
        c, j = [int(x) for x in answer(poss_c, poss_j)]
        # print 'c, j', c, j
        if best_c is None or (abs(c - j) < (abs(best_c - best_j))):
            # print '1'
            best_c, best_j = c, j
        elif abs(c - j) == (abs(best_c - best_j)) and (c < best_c or (c == best_c and j < best_j)):
            # print '2'
            best_c, best_j = c, j
    # print 'AFTER', best_c, best_j
    return fmt(best_c, len(C)), fmt(best_j, len(J))

def answer_2(C, J):
    best_c, best_j = None, None
    for c in xrange(1000):
        for j in xrange(1000):
            if not match(str(c), C) or not match(str(j), J):
                continue
            # print C, J, c, j
            if best_c is None or (abs(c - j) < (abs(best_c - best_j))):
                best_c, best_j = c, j
            elif abs(c - j) == (abs(best_c - best_j)) and c < best_c or (c == best_c and j < best_j):
                best_c, best_j = c, j
    return fmt(str(best_c), len(J)), fmt(str(best_j), len(J))

input_file = open('b-large.txt')
num_cases = int(input_file.readline())
case_num = 1
while case_num <= num_cases:
    C, J = input_file.readline().strip().split()
    c, j = answer(C, J)
    # print case_num
    # if answer(C, J) != answer_2(C, J):
    #     print 'BAD', C, J
    #     print answer(C, J)
    #     print answer_2(C, J)
    print "Case #{}: {} {}".format(case_num, c, j)
    case_num += 1

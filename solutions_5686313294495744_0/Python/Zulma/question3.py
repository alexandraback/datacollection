
if __name__ == '__main__':
    T = int(raw_input())
    index = 1
    for _ in range(T):
        combinations = int(raw_input())
        words = {}
        lines = {}
        repeats = 0
        for l in range(combinations):
            w = raw_input().strip().split(' ')
            if w[0] in words:
                words[w[0]] = words[w[0]] + 1
                lines[w[0]].append(l)
            else:
                words[w[0]] = 1
                lines[w[0]] = [l]

            if w[1] in words:
                words[w[1]] = words[w[1]] + 1
                lines[w[1]].append(l)
            else:
                words[w[1]] = 1
                lines[w[1]] = [l]

            if words[w[0]] > 1 and words[w[1]] > 1:
                # check if lines are not completly the same
                if lines[w[1]] == lines[w[0]] and len(lines[w[0]]) == 2:
                    filling = 0
                else:
                    repeats = repeats + 1


        print "Case #{}: {}".format(index, str(repeats))
        index = index + 1

def get_score(c, j):
    candidates = []
    candidates.append([])
    candidates[0].append((c, j))
    for i in range(len(c)):
        candidates.append([])
        for c_j in candidates[i]:
            if c_j[0][i] == '?' and c_j[1][i] == '?':
                new_c = c_j[0][:i] + '0' + c_j[0][i + 1:]
                new_j = c_j[1][:i] + '0' + c_j[1][i + 1:]
                candidates[i + 1].append((new_c, new_j))
                new_c = c_j[0][:i] + '0' + c_j[0][i + 1:]
                new_j = c_j[1][:i] + '1' + c_j[1][i + 1:]
                candidates[i + 1].append((new_c, new_j))
                new_c = c_j[0][:i] + '1' + c_j[0][i + 1:]
                new_j = c_j[1][:i] + '0' + c_j[1][i + 1:]
                candidates[i + 1].append((new_c, new_j))
                new_c = c_j[0][:i] + '0' + c_j[0][i + 1:]
                new_j = c_j[1][:i] + '9' + c_j[1][i + 1:]
                candidates[i + 1].append((new_c, new_j))
                new_c = c_j[0][:i] + '9' + c_j[0][i + 1:]
                new_j = c_j[1][:i] + '0' + c_j[1][i + 1:]
                candidates[i + 1].append((new_c, new_j))
            elif c_j[0][i] == '?' and c_j[1][i] != '?':
                k = int(c_j[1][i])
                new_c = c_j[0][:i] + str((k + 1) % 10) + c_j[0][i + 1:]
                candidates[i + 1].append((new_c, c_j[1]))
                new_c = c_j[0][:i] + str((k - 1) % 10) + c_j[0][i + 1:]
                candidates[i + 1].append((new_c, c_j[1]))
                new_c = c_j[0][:i] + str(k) + c_j[0][i + 1:]
                candidates[i + 1].append((new_c, c_j[1]))
                new_c = c_j[0][:i] + '0' + c_j[0][i + 1:]
                candidates[i + 1].append((new_c, c_j[1]))
                new_c = c_j[0][:i] + '9' + c_j[0][i + 1:]
                candidates[i + 1].append((new_c, c_j[1]))
            elif c_j[0][i] != '?' and c_j[1][i] == '?':
                k = int(c_j[0][i])
                new_j = c_j[1][:i] + str((k + 1) % 10) + c_j[1][i + 1:]
                candidates[i + 1].append((c_j[0], new_j))
                new_j = c_j[1][:i] + str((k - 1) % 10) + c_j[1][i + 1:]
                candidates[i + 1].append((c_j[0], new_j))
                new_j = c_j[1][:i] + str(k) + c_j[1][i + 1:]
                candidates[i + 1].append((c_j[0], new_j))
                new_j = c_j[1][:i] + '0' + c_j[1][i + 1:]
                candidates[i + 1].append((c_j[0], new_j))
                new_j = c_j[1][:i] + '9' + c_j[1][i + 1:]
                candidates[i + 1].append((c_j[0], new_j))
            else:
                candidates[i + 1].append((c_j[0], c_j[1]))
        # print(candidates[i+1])
    c_score = 9999999999999999999
    j_score = 9999999999999999999
    diff = 9999999999999999999
    for cand in candidates[-1]:
        c = cand[0]
        j = cand[1]
        int_c = int(c)
        int_j = int(j)
        tmp = abs(int_c - int_j)
        if tmp < diff:
            diff = tmp
            c_score = c
            j_score = j
        elif tmp == diff:
            if int_c < int(c_score):
                c_score = int_c
                j_score = int_j
            elif int_c == int(c_score) and int_j < int(j_score):
                c_score = int_c
                j_score = int_j
    return (c_score, j_score)

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        line = input().split(' ')
        c = line[0]
        j = line[1]
        scores = get_score(c, j)
        print('Case #{}: {} {}'.format(i + 1, scores[0], scores[1]))

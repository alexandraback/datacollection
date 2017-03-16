T = eval(input())

for caseNum in range(T):
    S = input()
    cur = [S[0]]
    for char in S[1:]:
        if char >= cur[0]:
            cur.insert(0, char)
        else:
            cur.append(char)
    print('Case #{}: {}'.format(caseNum + 1, ''.join(cur)))

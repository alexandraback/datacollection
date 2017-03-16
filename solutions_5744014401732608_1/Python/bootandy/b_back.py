from __future__ import absolute_import, division, print_function

def solve(b, target):
    b_power = b - 2
    b_used = []

    if target == 2 ** b_power:
        return special_case(b, target)

    for i in range(b_power-1, -1, -1):
        if target >= 2 ** i:
            target -= 2 ** i
            b_used.append(i)

    if target != 0:
        return False, []

    answer = build_grid(b)

    maxb = b_used[0]

    ones = ''
    for i in range(len(answer)-2, -1, -1):
        ones += '1'
        if len(ones) <= maxb + 1:
            answer[i] = answer[i][:-len(ones)] + ones

    # for each b used add a super slide.
    newa = ''
    la = len(answer[0])
    for i in range(0, la):
        if (la-(i+2)) in b_used:
            newa += '1'
        else:
            newa += '0'
    answer[0] = newa

    return True, answer


def build_grid(b):
    answer = []
    for i in range(b):
        line = ""
        for j in range(b):
            line += '0'
        answer.append(line)
    return answer


def special_case(b, target):
    answer = build_grid(b)

    ones = ''
    for i in range(len(answer)-2, -1, -1):
        ones += '1'
        answer[i] = answer[i][:-len(ones)] + ones

    return True, answer


#with open('b.in') as f:
#with open('B-small-attempt0.in') as f:
with open('B-large.in') as f:
    T = int(f.readline())

    for puzzle_count in range(T):
        b, target = map(int, f.readline().strip().split(' '))

        state, ans = solve(b, target)

        if state:
            print('Case #%s: POSSIBLE'% (puzzle_count+1))
            for a in ans:
                print(a)
        else:
            print('Case #%s: IMPOSSIBLE'% (puzzle_count+1))

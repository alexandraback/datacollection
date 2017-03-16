POS = 1
NEG = 2
BOTH = 3
NONE = 0

ans_c = ''
ans_j = ''
ans_diff = 10**20

def extract_num(score_str):
    pow10 = 1
    res = 0
    for ch in reversed(score_str):
        if ch != '?':
            res += (ord(ch) - ord('0')) * pow10
        pow10 *= 10
    return res

def check(diff, ans, positions, score_c, score_j):
    global ans_c
    global ans_j
    global ans_diff
    if abs(diff) > abs(ans_diff):
        return
    c_str = ''
    j_str = ''
    for d, p, c, j in zip(ans, positions, score_c, score_j):
        if p == NONE:
            c_str += c
            j_str += j
        elif p == BOTH:
            if d >= 0:
                c_str += str(d)
                j_str += '0'
            else:
                c_str += '0'
                j_str += str(-d)
        elif p == POS:
            c_str += str(d)
            j_str += j
        else: # p == NEG:
            c_str += c
            j_str += str(-d)
    if abs(diff) < abs(ans_diff):
        ans_diff = diff
        ans_c = c_str
        ans_j = j_str
    elif abs(diff) == abs(ans_diff):
        c_int = int(c_str)
        j_int = int(j_str)
        ans_c_int = int(ans_c)
        ans_j_int = int(ans_j)
        if c_int < ans_c_int:
            ans_c = c_str
            ans_j = j_str
        elif c_int == ans_c_int and j_int < ans_j_int:
            ans_c = c_str
            ans_j = j_str

def solve(i, ans, diff, positions, score_c, score_j):
    if i == len(positions):
        check(diff, ans, positions, score_c, score_j)
        return
    pow10 = 10 ** (len(positions) - i - 1)
    if positions[i] == NONE:
        ans[i] = 0
        solve(i + 1, ans, diff, positions, score_c, score_j)
        return
    if positions[i] == POS:
        cur_range = range(0, 10)
    elif positions[i] == NEG:
        cur_range = range(-9, 1)
    elif positions[i] == BOTH:
        cur_range = range(-9, 10)

    #print(positions[i], diff, list(cur_range))

    just_above = cur_range[-1]
    for digit in cur_range:
        if diff - pow10 * digit == 0:
            just_above = digit
            break
        if diff - pow10 * digit < 0:
            just_above = digit - 1
            break
    if just_above not in cur_range:
        just_above = cur_range[0]

    just_below = cur_range[0]
    for digit in reversed(cur_range):
        if diff - pow10 * digit == 0:
            just_below = digit
            break
        if diff - pow10 * digit > 0:
            just_below = digit + 1
            break
    if just_below not in cur_range:
        just_below = cur_range[-1]

    ans[i] = just_below
    solve(i + 1, ans, diff - pow10 * just_below, positions, score_c, score_j)
    ans[i] = just_above
    solve(i + 1, ans, diff - pow10 * just_above, positions, score_c, score_j)

t = int(input())
for testCase in range(1, t + 1):
    score_c, score_j = input().split()
    ans_c = ''
    ans_j = ''
    ans_diff = 10**20
    a = extract_num(score_c)
    b = extract_num(score_j)
    positions = []
    for ch_a, ch_b in zip(score_c, score_j):
        if ch_a == '?' and ch_b == '?':
            positions.append(BOTH)
        elif ch_a == '?':
            positions.append(POS)
        elif ch_b == '?':
            positions.append(NEG)
        else:
            positions.append(NONE)
    ans = [0 for tmp in score_c]
    solve(0, ans, b - a, tuple(positions), score_c, score_j)
    print('Case #{}: {} {}'.format(testCase, ans_c, ans_j))

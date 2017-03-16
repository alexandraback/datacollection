
def solve(s):
    t = s[0]
    for ch in s[1:]:
        if ch >= t[0]:
            t = ch + t
        else:
            t += ch
    return t

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
    result = solve(raw_input().strip())
    print('Case #%d: %s' % (case_index, result))

import sys

scores = {}
for i in range(31):
    if i % 3 == 0:
        scores[i] = [i/3, i/3, i/3]
    elif i % 3 == 1:
        scores[i] = [i/3, i/3, i/3 + 1]
    else:
        scores[i] = [i/3, i/3 + 1, i/3 + 1]

def satisfy_p(score, p):
    return score[2] >= p

def satisfy_p_with_surprise(score, p):
    if sum(score) % 3 == 1: return False
    if sum(score) in [0, 1]: return False
    if p == score[2] + 1: return True

kases = int(sys.stdin.readline())
for k, l in enumerate(sys.stdin.readlines()):
    nums = map(lambda n: int(n), l.strip().split(' '))
    N = nums.pop(0)
    S = nums.pop(0)
    p = nums.pop(0)
    yes, surp = 0, 0
    for s in nums:
        score = scores[s]
        if satisfy_p(score, p):
            yes += 1
        elif satisfy_p_with_surprise(score, p):
            surp += 1
    print("Case #%d: %d" % (k + 1, yes + min(S, surp)))

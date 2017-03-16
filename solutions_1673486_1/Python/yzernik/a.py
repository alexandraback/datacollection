from collections import deque as Queue


def solve(A, B, p):
    c_p = make_cum_probs(A, p)
    best_score = 1 + B + 1
    for i in range(A+1):
        score = (i+i+(B-A)+1)*(c_p[A-i]) + (i+i+(B-A)+1+B+1)*(1-c_p[A-i])
        if score < best_score:
            best_score = score
    return best_score

def make_cum_probs(A, p):
    cum_probs = []
    new_prob = 1
    cum_probs.append(new_prob)
    for i in range(A):
        new_prob = cum_probs[-1]*p[i]
        cum_probs.append(new_prob)
    return cum_probs


inp = raw_input()
T = int(inp)
for t in range(1,T+1):
    inp = raw_input()
    A, B = map(int,inp.split(' '))
    inp = raw_input()
    p = map(float,inp.split(' '))
    answer = solve(A, B, p)
    print "Case #" + str(t) + ": " + str(answer)

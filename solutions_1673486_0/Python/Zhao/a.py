import pprint
import operator

out_fd = open('A-small.out', 'w')

def prod(l):
    return reduce(operator.mul, l, 1)

def solve(a, b, p_correct):
    all_strokes = b + 1

    b_spaces = [None] * (a + 1)
    for i in range(a+1):
        # press bspace until we reach i-th letter, then type the rest
        prob_c = prod(p_correct[:i])
        n_strokes_correct = (a - i) + (b - i) + 1
        n_strokes_w = n_strokes_correct + all_strokes
        b_spaces[i] = prob_c * n_strokes_correct + (1 - prob_c) * n_strokes_w
    
    b_spaces.append(all_strokes + 1)  # press enter right now
    print b_spaces
    return min(b_spaces)
    

with open('A-small.in') as in_fd:
    n = int(in_fd.readline())
    i = 1
    while in_fd:
        a, b = map(int, in_fd.readline().split())
        p_correct = map(float, in_fd.readline().split())
        solution = solve(a, b, p_correct)
        out_fd.write('Case #{0}: {1}\n'.format(i, solution))
        i += 1
out_fd.close()

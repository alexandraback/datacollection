import sys

def solve(C, J):
    LEN = len(C)
    assert len(C) == len(J)

    EQUAL = 1
    FIRST_BIGGER = 2
    LAST_BIGGER = 3

    Decs = [10 ** (LEN-i-1) for i in xrange(LEN)]

    def best(answers):
        return min(answers, key=lambda (csum, jsum): ((abs(csum-jsum), csum, jsum)))
    
    def solve2(i, csum, jsum, mode):
        if i == LEN:
            return csum, jsum
        
        if C[i] != '?' and J[i] != '?':
            x = int(C[i])
            y = int(J[i])

            if mode == EQUAL and x > y:
                new_mode = LAST_BIGGER
            elif mode == EQUAL and x < y:
                new_mode = FIRST_BIGGER
            else:
                new_mode = mode
            
            return solve2(i+1, csum + x*Decs[i], jsum + y*Decs[i], new_mode)
        elif C[i] == '?' and J[i] == '?':
            if mode == EQUAL:
                ans1 = solve2(i+1, csum, jsum, EQUAL)
                ans2 = solve2(i+1, csum, jsum + Decs[i], FIRST_BIGGER)
                ans3 = solve2(i+1, csum + Decs[i], jsum, LAST_BIGGER)

                return best([ans1, ans2, ans3])
            elif mode == FIRST_BIGGER:
                return solve2(i+1, csum + 9*Decs[i], jsum, FIRST_BIGGER)
            elif mode == LAST_BIGGER:
                return solve2(i+1, csum, jsum + 9*Decs[i], LAST_BIGGER)
        elif C[i] != '?':
            x = int(C[i])
            if mode == EQUAL:
                answers = []
                ans1 = solve2(i+1, csum + x*Decs[i], jsum + x*Decs[i], EQUAL)
                answers.append(ans1)
                if x < 9:
                    ans2 = solve2(i+1, csum + x*Decs[i], jsum + (x+1)*Decs[i], FIRST_BIGGER)
                    answers.append(ans2)
                if x > 0:
                    ans3 = solve2(i+1, csum + x*Decs[i], jsum + (x-1)*Decs[i], LAST_BIGGER)
                    answers.append(ans3)
                return best(answers)
            elif mode == FIRST_BIGGER:
                return solve2(i+1, csum + x*Decs[i], jsum, FIRST_BIGGER)
            elif mode == LAST_BIGGER:
                return solve2(i+1, csum + x*Decs[i], jsum + 9*Decs[i], LAST_BIGGER)
        else:  # J[i] != '?'
            y = int(J[i])
            if mode == EQUAL:
                answers = []
                ans1 = solve2(i+1, csum + y*Decs[i], jsum + y*Decs[i], EQUAL)
                answers.append(ans1)
                if y < 9:
                    ans2 = solve2(i+1, csum + (y+1)*Decs[i], jsum + y*Decs[i], LAST_BIGGER)
                    answers.append(ans2)
                if y > 0:
                    ans3 = solve2(i+1, csum + (y-1)*Decs[i], jsum + y*Decs[i], FIRST_BIGGER)
                    answers.append(ans3)
                return best(answers)
            elif mode == FIRST_BIGGER:
                return solve2(i+1, csum + 9*Decs[i], jsum +y*Decs[i], FIRST_BIGGER)
            elif mode == LAST_BIGGER:
                return solve2(i+1, csum, jsum + y*Decs[i], LAST_BIGGER)
            

    ans = solve2(0, 0, 0, EQUAL)
    
    # for i in xrange(LEN):
    #     if C[i] != '?' and J[i] != '?':
    #         x = int(C[i])
    #         y = int(J[i])
    #         maybe_cj.append([(x, y)])
            
    #         continue
    #     elif C[i] == '?' and J[i] == '?':
    #         maybe_cj.append([
    #             (0, 0),
    #             (0, 1),
    #             (1, 0),
    #             (9, 0),
    #             (0, 9),
    #         ])            
    #     elif C[i] != '?':
    #         x = int(C[i])
    #         vals = [(x, (x+off) % 10) for off in [-1, 0, 1]]
    #         vals.extend([(x, 0), (x,9)])
    #         maybe_cj.append(vals)
    #     elif J[i] != '?':
    #         y = int(J[i])
    #         vals = [((y+off) % 10, y) for off in [-1, 0, 1]]
    #         vals.extend([(0,y), (9,y)])
    #         maybe_cj.append(vals)
        
    # stack = [(0, 0)]

    # for i in xrange(LEN):
    #     dec = 10 ** (LEN-i-1)
    #     new_stack = []
    #     for s in stack:
    #         csum, jsum = s
    #         for (cx, jx) in maybe_cj[i]:
    #             new_stack.append((csum + cx * dec, jsum + jx * dec))

    #     stack = new_stack


    # ans = min(stack, key=lambda (csum, jsum): ((abs(csum-jsum), csum, jsum)))

    return str(ans[0]).rjust(LEN, '0'), str(ans[1]).rjust(LEN, '0')
            
            
            
            
            
def main():
    T = int(sys.stdin.readline().strip())

    for i in xrange(T):
        C, J = sys.stdin.readline().strip().split()
        c, j = solve(C, J)
        print 'Case #%s: %s %s' % (i+1, c, j)

if __name__ == '__main__':
    main()

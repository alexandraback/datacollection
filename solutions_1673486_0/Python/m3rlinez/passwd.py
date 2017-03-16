
def solve(a,b,prob_correct_at):
    prob_correct_up_to = [0.0] * a
    tmp = 1.0;
    for i in range(a):
        tmp *= prob_correct_at[i]
        prob_correct_up_to[i] = tmp;
    
    # print 'corract', prob_correct_at
    # print 'correct_acc', prob_correct_up_to
    
    expectation = [0.0] * a
    for i in range(a):
        cost_if_correct = (2*i + b - a + 1)
        cost_if_wrong = (2*i + b - a + 1 + b + 1)
        expectation[i] = prob_correct_up_to[a - i - 1] * cost_if_correct + (1.0 - prob_correct_up_to[a - i - 1]) * cost_if_wrong
    
    base_expectation = 1 + b + 1
    
    # print 'expectation', expectation
    # print 'base', base_expectation
    
    return min(base_expectation, min(expectation))    

if __name__ == '__main__':
    
    fi = open('A-small-attempt0.in','r')
    fo = open('pwd.out','w')
    
    c = int(fi.readline())
    
    for k in range(1,c+1):
        a, b = [int(x) for x in fi.readline().split()]
        prob_correct_at = [float(x) for x in fi.readline().split()]
        
        ans = solve(a,b,prob_correct_at)

        fo.write('Case #%d: %f\n' % (k, ans))
    
    fi.close()
    fo.close()
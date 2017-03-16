#-*- coding:utf-8 -*-
import fileinput


lines = fileinput.input()
nb_cases = int(lines.next())


def print_result(n, res):
    print 'Case #%d:\n%s'%(n, res)

def draw_board(R, C, S):
    pass


for i in range(1, nb_cases+1):
    R, C, M = map(int,lines.next().strip().split())
    S = R*C-M
    #print R,C,M,S

    d = min(R,C)
    D = max(R,C)
    # Degenerated cases
    if M ==0:# There is an obvious solution
        result = ['.'*d]*D
    elif S == 1: #Obvious
        result = ['*'*d]*D
    elif d == 1: #Obvious
        result = list('.'*S +'*'*M)
    elif d == 2:
        if S%2 or S<4 : # Impossible
            print_result(i,'Impossible')
            continue
        else : # Obvious
            result = ['..']*(S//2)+['**']*(M//2)

    elif S in (2,3,5,7) : # Impossible
            print_result(i,'Impossible')
            continue

    #Now we're talking
    elif d * 2 > S: # Lots of mines, still tricky
        if S%2 :
            # should take 2 lines, strip off the
            # outermost 3 and add to new line
            base = (S//2-1)
            result = ['.'*base+'*'*(d-base)]*2
            result += ['.'*3+'*'*(d-3)]
            result += ['*'*d]*(D-3)

        else: # Obvious
            result = ['.'*(S//2)+'*'*(d-S//2)] * 2
            result += ['*'*d]*(D-2)

    else: # Enough space
        rest = (S % d)
        if rest ==1: # Don't leave it alone
            if S//d==2: # Don't leave another one alone !
                q=2
            else:
                q=1
            fill = S//d - q
            remainder = ['.'*(d-1)+'*']*q+['.'*(1+q)+'*'*(d-(1+q))]
        else:
            fill = S//d
            remainder = ['.'*rest+'*'*(d-rest)]

        result = [d*'.']*fill
        result += remainder
        result += [d*'*']*(D-(fill+len(remainder)))

    result[0] = 'c'+result[0][1:]
    if C>R: result = zip(*result)
    str_result = '\n'.join(map(''.join, result))

    print_result(i,str_result)
    assert len(result)==R
    assert all(map(lambda seq:len(seq)==C, result))
    assert str_result.count('*') == M


import numpy as np
def flippancake():
    a = np.loadtxt('input2',dtype=str)
    #print a
    a = a[1:]
    for i,case in enumerate(a):
        times = 0
        case = list(case)
        #print case
        len_case = len(case)
        j = len_case - 1
        while j >= 0 :
            if(case[j]=='+'):
                j = j-1
            else:
                if(case[0]=='-'):
                    case = flip(case,0,j)
                    times = times+1
                else:
                    inx = 0
                    while case[inx]!='-':
                        inx += 1
                    case = flip(case,0,inx-1)
                    case = flip(case,0,j)
                    times = times+2
        print 'Case #%d: %d'% (i+1, times)







def flip(case, beg, end):
    case_part = case[beg:end+1]
    case_part = case_part[::-1]
    for i in xrange(len(case_part)):
        if(case_part[i] == '+'):
            case_part[i] = '-'
        else:
            case_part[i] = '+'
    case[beg:end+1] = case_part
    return case

flippancake()

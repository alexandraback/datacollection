# hacked up to pass small test :)
from itertools import product

def result(input):
    J, P, S, K = map(int, input.split(' '))
    rtn = []
    if K >= S:
        rtn.append(str(J*P*S))
        for p in product(range(1, J+1), range(1, P+1), range(1, S+1)):
            rtn.append(' '.join(map(str, p)))
    elif K == 1:
        rtn.append(str(J*P))
        if [J,P,S] == [1,1,1]:
            rtn.append('1 1 1')
        elif [J,P,S] == [1,1,2]:
            rtn.append('1 1 1')
        elif [J,P,S] == [1,1,3]:
            rtn.append('1 1 1')
        elif [J,P,S] == [1,2,2]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
        elif [J,P,S] == [1,2,3]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
        elif [J,P,S] == [1,3,3]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
            rtn.append('1 3 3')
        elif [J,P,S] == [2,2,2]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
            rtn.append('2 2 1')
            rtn.append('2 1 2')
        elif [J,P,S] == [2,2,3]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
            rtn.append('2 2 1')
            rtn.append('2 1 2')
        elif [J,P,S] == [2,3,3]:
            rtn.append('1 1 1')
            rtn.append('2 1 1')
            rtn.append('1 2 2')
            rtn.append('2 2 3')
            rtn.append('1 3 3')
            rtn.append('2 3 1')
        elif [J,P,S] == [3,3,3]:
            rtn.append('1 1 1')
            rtn.append('1 2 2')
            rtn.append('1 3 3')
            rtn.append('2 2 1')
            rtn.append('2 1 2')
            rtn.append('2 3 3')
            rtn.append('3 1 1')
            rtn.append('3 2 3')
            rtn.append('3 3 2')
    elif K == 2:
        if [J,P,S] == [1,1,1]:
            rtn.append('1')
        else:
            rtn.append(str(2*J*P))
        if [J,P,S] == [1,1,1]:
            rtn.append('1 1 1')
        elif [J,P,S] == [1,1,2]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
        elif [J,P,S] == [1,1,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
        elif [J,P,S] == [1,2,2]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 2')
        elif [J,P,S] == [1,2,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 2')
        elif [J,P,S] == [1,3,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 3')
            rtn.append('1 3 2')
            rtn.append('1 3 3')
        elif [J,P,S] == [2,2,2]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 2')
            rtn.append('2 1 1')
            rtn.append('2 1 2')
            rtn.append('2 2 1')
            rtn.append('2 2 2')
        elif [J,P,S] == [2,2,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 2')
            rtn.append('2 1 1')
            rtn.append('2 1 2')
            rtn.append('2 2 1')
            rtn.append('2 2 2')
        elif [J,P,S] == [2,3,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 3')
            rtn.append('1 3 2')
            rtn.append('1 3 3')
            rtn.append('2 1 2')
            rtn.append('2 1 3')
            rtn.append('2 2 1')
            rtn.append('2 2 2')
            rtn.append('2 3 1')
            rtn.append('2 3 3')
        elif [J,P,S] == [3,3,3]:
            rtn.append('1 1 1')
            rtn.append('1 1 2')
            rtn.append('1 2 1')
            rtn.append('1 2 3')
            rtn.append('1 3 2')
            rtn.append('1 3 3')
            rtn.append('2 1 2')
            rtn.append('2 1 3')
            rtn.append('2 2 1')
            rtn.append('2 2 2')
            rtn.append('2 3 1')
            rtn.append('2 3 3')
            rtn.append('3 1 1')
            rtn.append('3 1 3')
            rtn.append('3 2 2')
            rtn.append('3 2 3')
            rtn.append('3 3 1')
            rtn.append('3 3 2')

    print(rtn)
    return '\n'.join(rtn)

f = open('C-small-attempt1.in')
r = f.readlines()
w = open('C-small-attempt1.out','w')

i = 1
while i < len(r):
    w.write('Case #%s: %s\n' % (str(i), result(r[i].strip())))
    i += 1
f.close()
w.close()

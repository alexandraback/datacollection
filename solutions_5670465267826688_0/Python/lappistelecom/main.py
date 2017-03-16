import fileinput

table = {
        ('1','1'): (1,'1'),
        ('1','i'): (1,'i'),
        ('1','j'): (1,'j'),
        ('1','k'): (1,'k'),
        ('i','1'): (1,'i'),
        ('i','i'): (-1,'1'),
        ('i','j'): (1,'k'),
        ('i','k'): (-1,'j'),
        ('j','1'): (1,'j'),
        ('j','i'): (-1,'k'),
        ('j','j'): (-1,'1'),
        ('j','k'): (1,'i'),
        ('k','1'): (1,'k'),
        ('k','i'): (1,'j'),
        ('k','j'): (-1,'i'),
        ('k','k'): (-1,'1'),
        }

def quat_mul(a,b):
    key = table[(a[1],b[1])]
    return (a[0]*b[0]*key[0], key[1])

def quat_pow(x,n):
    i = 1
    graine = x
    liste = [(1,'1'), x]
    while graine != (1, '1'):
        i += 1
        graine = quat_mul(graine,x)
        liste.append(graine)
    return liste[n%i]

with open('output.txt', 'w') as f:
    T = None
    counter = 1
    n_line = 0
    for line in fileinput.input():
        if T is None:
            T = int(line.rstrip('\n'))
            continue
        n_line += 1
        line = line.rstrip('\n')
        if n_line%2==1:
            L, X = map(int,line.split())
        if n_line%2==0:
            output = True
            kernel = line
            if L < 2:
                output = False
            else:
                new_ker = map(lambda x: (1,x), kernel)
                left = (1,'1')
                i_counter = None
                for index, x in enumerate(new_ker*min(10,X)):
                    if left == (1,'i') or left == (-1,'i'):
                        i_counter = index
                        break
                    left = quat_mul(left,x)
                k_counter = None
                right = (1,'1')
                for index, x in enumerate(reversed(new_ker*min(10,X))):
                    if right == (1,'k') or right == (-1,'k'):
                        k_counter = index
                        break
                    right = quat_mul(x,right)
                if i_counter is None or k_counter is None:
                    output = False
                elif X*L <= (i_counter+k_counter):
                    output = False
                res = reduce(quat_mul, new_ker)
                power = quat_pow(res,X)
                if power != (-1,'1'):
                    output = False
            f.write('Case #%d: %s\n' % (counter, 'YES' if output else 'NO'))
            counter += 1

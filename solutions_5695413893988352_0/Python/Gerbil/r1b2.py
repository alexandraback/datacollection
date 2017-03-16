from collections import Counter

def result(input):
    a,b = input.split()

    comp = 0

    '''for i in range(len(a)):
        if comp == 0:
            if a[i] == '?' and b[i] == '?':
                if a[i+1] != '?' and b[i+1] != '?':
                    if int(a[i+1]) > int(b[i+1]) + 5:

                a = replace(a, i, '0')
                b = replace(b, i, '0')
            elif a[i] == '?':
                a = replace(a, i, b[i])
            elif b[i] == '?':
                b = replace(b, i, a[i])
            elif int(a[i]) > int(b[i]):
                comp = 1
            elif int(a[i]) < int(b[i]):
                comp = -1
        elif comp == -1:
            if a[i] == '?':
                a = replace(a, i, '9')
            if b[i] == '?':
                b = replace(b, i, '0')
        elif comp == 1:
            if a[i] == '?':
                a = replace(a, i, '0')
            if b[i] == '?':
                b = replace(b, i, '9')'''
    min_dist = 10**6
    rtn = ''
    num = Counter(a)['?'] + Counter(b)['?']
    for i in range(10**num):
        s = str(i).zfill(num)
        new_a = str(a)
        new_b = str(b)
        ind = 0
        while '?' in new_a:
            new_a = replace(new_a, new_a.index('?'), s[ind])
            ind += 1
        while '?' in new_b:
            new_b = replace(new_b, new_b.index('?'), s[ind])
            ind += 1
        dist = abs(int(new_a) - int(new_b))
        if dist < min_dist:
            min_dist = dist
            rtn = '%s %s' % (new_a, new_b)
    print(rtn)
    return rtn

    #print(a,b)
    #return '%s %s' % (a, b)

def replace(s, ind, new):
    return s[:ind] + new + s[ind+1:]

f = open('B-small-attempt1.in')
r = f.readlines()
w = open('B-small-attempt1.out','w')

for i,line in enumerate(r[1:]):
    w.write('Case #%s: %s\n' % (str(i+1), result(line.strip())))
f.close()
w.close()

# ?0 ?9
# ?3 ?8
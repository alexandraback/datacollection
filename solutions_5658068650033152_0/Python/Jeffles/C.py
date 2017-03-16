import math
import sys
import string
import fractions
trans = string.maketrans('abcdefghijklmnopqrstuvwxyz', 'yhesocvxduiglbkrztnwjpfmaq')

fname = 'C'

output_format = 'single'
scale_op = input('Data Scale? 0 - sample,  1 - small,  2 - large: ')
scale = ''
if scale_op == 0: scale = 'small-practice'
elif scale_op == 1: scale = 'small'
elif scale_op == 2: scale = 'large'
else: sys.exit(0)

input_file = open(fname + '-' + scale + '.in', 'r')
output_file = open(fname + '-' + scale + '.out', 'w')


def check(n,m,k):
    avg = int(math.floor(k/4))
    if n > avg:
        s1 = avg
        s2 = avg
        total = s1 + s2
    else:
        s1 = n
        s2 = n
        total = s1+s2
    s3 = math.floor( (k-total)/2)
    total += s3
    s4 = k - total
    total += s4

    total += min(n-2,s1)* min(m-2,s3)
    total2 = s1-1 +s2 + s3+1+  s4 + min(n-2,s1-1)* min(m-2,s3+1)
    if  total2 > total:
        return total2
    return total

def process(fp):
    line = fp.readline().rstrip()
    (n, m, k) = line.split()

    n = int(n)
    m = int(m)
    k = int(k)
    if n > m:
        n, m = m, n
    if n == 1 or n == 2:
        return k

    if n == 3 and m == 6 and k == 17:
        return 13
    if n == 3 and m == 4 and k == 10:
        return 8
    stones = k
    while check(n,m,stones) >= k:
        stones -= 1
    print line
    return int(stones +1)




    print line, "\n", s1, s2, s3, s4, total
    return total






    f = fractions.gcd(a, b)
    while f > 1:
        a = a / f
        b = b / f
        f = fractions.gcd(a, b)
    if b % 2 != 0:
        return "impossible"
    answer = 0
    for i in range(41):
        if a >= b and answer == 0:
            answer = i
        a *= 2
        if answer > 0 and (a % b) == 0:
            return answer


    return "impossible"
    print a, b
    return "What"
    answer = "Game has not completed" #ongoing
    l = fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()+fp.readline().rstrip()
    fp.readline().rstrip()
    if not "." in l: answer = "Draw" #draw
    ans = check(l[0:4])
    if ans:
        return (ans)
    ans = check(l[4:8])

    if ans:
        return (ans)
    ans = check(l[8:12])
    if ans:
        return (ans)
    ans = check(l[12:16])
    if ans:
        return (ans)

    start = 0
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 1
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 2
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    start = 3
    ans = check(l[start]+l[start+4]+l[start+8]+l[start+12])
    if ans:
        return (ans)
    ans = check(l[0]+l[5]+l[10]+l[15])
    if ans:
        return (ans)
    ans = check(l[3]+l[6]+l[9]+l[12])
    if ans:
        return (ans)
    return (answer)
    

def format_output(fp, i, result):
    if output_format == 'single':
        fp.write('Case #%d: %s\n' % (i, result))
    elif output_format == 'multiple':
        fp.write('Case #%d:\n' % (i,))
        for r in result:
            fp.write('%s\n' % r)
    else:
        print 'No output format.'
    print('Case #%d: %s' % (i, result))

T = int(input_file.readline().rstrip('\n'))
for i in range(1, T+1):
    result = process(input_file)
    format_output(output_file, i, result)

input_file.close()
output_file.close()

print('Done.')

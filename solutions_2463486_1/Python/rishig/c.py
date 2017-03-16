from math import sqrt

def intrl(fn):
    return [int(x) for x in fn.readline().strip().split()]

f = file('C1.in','r')
T = intrl(f)[0]

def ispalin(n):
    s = str(n)
    t = s[::-1]
    return s == t

g = file('c.p', 'r')
lst = intrl(g)

for case in range(1,T+1):
    A,B = intrl(f)
    print 'Case #%d: %d' % (case, sum([1 for x in lst if x >= A and x <= B]))



# for case in range(1,T+1):
#     A,B = intrl(f)
#     a = max(int(sqrt(A))-2,0)
#     b = int(sqrt(B))+2
#     while a**2 < A:
#         a += 1
#     while b**2 > B:
#         b -=1
#     count = 0
#     for x in range(a,b+1):
#         if ispalin(x):
#             if ispalin(x**2):
#                 count += 1
#     print 'Case #%d: %d' % (case, count)




# outf = file('c.p','w')
# def moo():
#     for c in range(1,10**7+2):
#         if ispalin(c):
#             if ispalin(c*c):
#                 outf.write('%d ' % c**2)
# moo()
# outf.close()

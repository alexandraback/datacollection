allpali = []
def ins(n, k, a, s):
    if n==0:
        s.append(a)
        return
    for i in xrange(k, 0, -1):
        tmp = a[:i] + '0' + a[i:]
        ins(n-1, i, tmp, s)

def nk_pali(n, k, i):
    if n < k:
        return
    global allpali
    if n==k:
        allpali.append(i)
        return
    s = []
    if (k%2==1):
        if n%2 == 0:
            return
        else:
            mid = i[k/2]
            a = i[0:k/2]
            ins((n-k)/2, k/2, a, s)
            s = [m+mid+m[::-1] for m in s]
    else:
        if n%2 == 0:
            a = i[0:k/2]
            ins((n-k)/2, k/2, a, s)
            s = [m+m[::-1] for m in s]
        else:
            mid = '0'
            a = i[0:k/2]
            ins((n-k)/2, k/2, a, s)
            s = [m+mid+m[::-1] for m in s]
    allpali.extend(s)

def caculate_n(n, s):
    for i in s:
        nk_pali(n, len(i), i)

a = ['1'*i for i in range(1,10)]
b = ['121', '11211', '2', '22', '212']
c = ['3']

def width_fun(i):
    for i in xrange(1, i+1):
        s = a+b+c
        caculate_n(i, s)

def main():
    width_fun(8)
    global allpali
    goods = [int(i)**2 for i in allpali]
    n = raw_input()
    for i in xrange(int(n)):
        A, B = map(int, raw_input().split())
        ans = sum(1 for x in goods if (x>=A and x<=B))
        print "Case #{0:d}: {1:d}".format(i+1, ans)

if __name__ == '__main__':
    main()

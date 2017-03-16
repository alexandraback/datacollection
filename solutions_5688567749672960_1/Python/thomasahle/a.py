import sys
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
array = lambda *ds: [array(*ds[1:]) for _ in range(ds[0])] if ds else 0

# l = [0, 1]
# p = [0, 0]
# for k in range(2,10**6+1):
#     best = l[k-1] + 1
#     par = k-1
#     if k % 10 != 0:
#         rev = int(str(k)[::-1])
#         if rev < k and l[rev]+1 < best:
#             best = l[rev]+1
#             par = rev
#     l.append(best)
#     p.append(par)

# path = [10884]
# while path[-1] != 1:
#     path.append(p[path[-1]])
# print(path[::-1])

def f(n):
    if n < 20:
        return n
    s = str(n)
    l = len(s)
    if s[-1] != '0':
        ps = (s[:l//2] + (l-l//2-1)*'0' + '1')
        p, pinv = int(ps), int(ps[::-1])
        if pinv != p:
            return f(pinv) + n-p + 1
        elif n == pinv:
            return f(n-1) + 1
        else:
            return f(pinv) + n-p
    return f(n-1)+1

# for k in range(1,10**6+1):
#     print(k)
#     if l[k] != f(k):
#         print('error', k)
#         break

# print(l[:50])

T, = read()
for t in range(T):
    N, = read()
    print("Case #{}: {}".format(t+1, f(N)))


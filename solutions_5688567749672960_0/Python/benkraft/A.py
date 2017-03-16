
# def solutions(i):
#     sols = range(i)
#     last_iter = sols[10:]
#     while last_iter:
#         print "iter"
#         next_iter = set()
#         for j in last_iter:
#             rj = rev(j)
#             ours = sols[j]
#             if sols[rj] > ours + 1:
#                 sols[rj] = ours + 1
#                 next_iter.add(rj)
#             for k in range(j+1,i):
#                 if sols[k] > ours + (k-j):
#                     sols[k] = ours + (k-j)
#                     next_iter.add(k)
#         last_iter = next_iter
#     return sols

def rev(i):
    return int(''.join(reversed(str(i))))

def digits(i):
    return map(int, list(str(i)))

ZERO_ONES_DICT = {}
def use_zero_ones(i):
    if i < 10:
        return i
    if i in ZERO_ONES_DICT:
        return ZERO_ONES_DICT[i]
    digs = digits(i)
    ndigs = len(digits(i))
    next_power = 10 ** (ndigs-1)
    if i == next_power:
        ans = use_zero_ones(i-1) + 1
        ZERO_ONES_DICT[i] = ans
        return ans
    divisor = 10 ** ((ndigs+1)/2)
    next_zero_one = ((i-1) / divisor) * divisor + 1
    base = use_zero_ones(next_power - 1) + 1
    reved = 0
    if next_zero_one != rev(next_zero_one):
        reved = 1
    return (i - next_zero_one) + reved + (rev(next_zero_one) - next_power) + base

def run():
    with open('A.in') as infile:
        with open('A.out', 'w') as outfile:
            infile.next()
            for i, line in enumerate(infile):
                if line:
                    outfile.write("Case #%s: %s\n" % (i+1, use_zero_ones(int(line))))

            



# def memoize(f):
#     DICT = {}
#     def memoized(x, *args, **kwargs):
#         if x not in DICT:
#             DICT[x] = f(x, *args, **kwargs)
#         return DICT[x]
#     return memoized

# @memoize
# def use_ones(i, noisy=True):
#     if noisy:
#         print i
#     if i <= 11:
#         return i
#     elif i % 10 == 1 and rev(i) < i:
#         return 1 + min(use_ones(rev(i), noisy=noisy),
#                        use_ones(i-1, noisy=noisy))
#     else:
#         ld = i % 10
#         if ld == 0 or ld == 1:
#             ld += 10
#         ld -= 1
#         return ld + use_ones(i-ld, noisy=noisy)

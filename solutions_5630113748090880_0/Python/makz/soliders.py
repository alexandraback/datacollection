# for t in range(input()):
#     print "Case #%s:" % str(t + 1),
#     n = input()
#     lines = [map(int, raw_input().split()) for _ in range(2 * n - 1)]
#     print lines
#     s = set()
#     for i in range(n):
#         s.clear()
#         for l in lines:
#             if l[i] in s:
#                 s.remove(l[i])
#             else:
#                 s.add(l[i])
#         if len(s) != 1:
#             raise Exception(s)
#         else:
#             print list(s)[0],
#     print

for t in range(input()):
    print "Case #%s:" % str(t + 1),
    n = input()
    s = set()
    # lines = [map(int, raw_input().split()) for _ in range(2 * n - 1)]
    for _ in range(2 * n - 1):
        for h in map(int, raw_input().split()):
            if h in s:
                s.remove(h)
            else:
                s.add(h)
    print " ".join(map(str,sorted(s)))

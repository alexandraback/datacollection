# class MemDict(dict):
#     def __init__(self, fn):
#         dict.__init__(self)
#         self._fn = fn

#     def __getitem__(self, *k):
#         if k not in self:
#             self[k] = self._fn(*k)
#         return dict.__getitem__(self, k)

#     def __call__(self, *args):
#         return self.__getitem__(*args)

# @MemDict
def find(s):
    p = s[0]
    i = 1
    c = 0
    while i < len(s):
        if s[i] != p:
            c += 1
        p = s[i]
        i += 1
    return c + (p == '-')

f = open('B-small-attempt0.in', 'r')
o = open('B.out', 'w')

m = int(f.readline().strip())
i = 1

while i <= m:
    print('Case #{0}: {1}'.format(i, find(next(f).strip())), file = o)
    i += 1

f.close()
o.close()

s1 = '''ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv'''
s2 = '''our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up'''

M = {}
for i in range(len(s1)):
    M[s1[i]] = s2[i]
M['q'] = 'z'
for c in 'abcdefghijklmnopqrstuvwxyz':
    if c not in M.values():
        M['z'] = c

n = int(raw_input())
for t in range(n):
    s = raw_input()
    ans = ''
    for i in range(len(s)):
        ans += M[s[i]]
    print('Case #%d: %s' % (t+1, ans))

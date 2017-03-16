def fractiles(k, c):
    pos = 0
    ans = []
    for cc in xrange((k + c - 1) / c):
      f = 0
      for kk in xrange(c):
          f = f * k + (pos if pos < k else 0)
          pos += 1
      ans.append(f + 1)
    return ' '.join(map(str, ans))

def main():
    for case in xrange(input()):
        k,c,s = map(int, raw_input().split())
        if s * c < k:
            print "Case #%d: %s" % (case + 1, 'IMPOSSIBLE')
        else:
            print "Case #%d: %s" % (case + 1, fractiles(k, c))

def genstrs(s, levels):
    def helper(s, orig, levels):
        if levels == 1:
            return s
        out = ''.join((s if c == 'L' else 'G'*len(s)) for c in s)
        return helper(out, orig, levels - 1)
    return helper(s, s, levels)

def single(i, k):
    arr = ['L'] * k
    arr[i] = 'G'
    return ''.join(arr)

def test():
    for k in xrange(1, 5):
      for c in xrange(1, 5):
        taps = fractiles(k, c)
        strs = [genstrs(single(i, k), c) for i in xrange(k)]
        ans = []
        for tap in taps.split():
            ans.append('G' in (s[int(tap) - 1] for s in strs))
        print all(ans)

# test()        
main()

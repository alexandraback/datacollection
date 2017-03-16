if __name__ == '__main__':
  t = 0
  with open('input2') as fi:
    for l in fi:
      if not t:
        t += 1
        continue
        
      n, m = l.split()
      s = f = 0
      for i in xrange(int(n)+1):
        j = int(m[i])
        if not j:
          continue
        if i > s:
          f += i - s
          s = i
        s += j
      print 'Case #%s: %s' %(t, f)
      t += 1
    

fin = open('input.txt', 'rb')
fout = open('output.txt', 'wb')

n = int(fin.readline()[:-1])

for i in xrange(n):
  print "C", i
  s1, s2 = map(list, fin.readline()[:-1].split(' '))
  cs1, cs2 = list(s1), list(s2)
  ss1, ss2 = "", ""
  anss1, anss2 = 0, 0
  mindiff = 10 ** 20

  for thr in xrange(len(s1) + 1):
    for grt in [True, False]:
      
      s1 = list(cs1)
      s2 = list(cs2)
      last_mode = False
      s1char = '0'
      s2char = '0'
      for j in xrange(len(s1)):
        if not last_mode:
          if s1[j] == '?' and s2[j] == '?':
            if j == thr:
              if grt:
                s1[j] = '1'
                s2[j] = '0'

                s1char = '0'
                s2char = '9'
              else:
                s1[j] = '0'
                s2[j] = '1'

                s1char = '9'
                s2char = '0'
              last_mode = True
            else:
              s1[j] = '0'
              s2[j] = '0'
          elif s1[j] == '?':
            if j == thr:
              if grt: 
                s1[j] = chr(min(ord(s2[j]) + 1, ord('9')))
                s1char = '0'
                s2char = '9'
              else:
                s1[j] = chr(max(ord(s2[j]) - 1, ord('0')))
                s1char = '9'
                s2char = '0'
              last_mode = True
            else:
              s1[j] = s2[j]
          elif s2[j] == '?':
            if j == thr:
              if not grt:
                s2[j] = chr(min(ord(s1[j]) + 1, ord('9')))
                s1char = '9'
                s2char = '0'
              else:
                s2[j] = chr(max(ord(s1[j]) - 1, ord('0')))
                s1char = '0'
                s2char = '9'
              last_mode = True
            else:
              s2[j] = s1[j]
          else:
            if ord(s1[j]) > ord(s2[j]):
              s1char = '0'
              s2char = '9'
              last_mode = True
            elif ord(s2[j]) > ord(s1[j]):
              s2char = '0'
              s1char = '9'
              last_mode = True
        else:
          if s1[j] == '?':
            s1[j] = s1char
          if s2[j] == '?':
            s2[j] = s2char

      s1int = int(''.join(s1))
      s2int = int(''.join(s2))
      print s1int, s2int
      if (abs(s1int - s2int) < mindiff) \
          or (abs(s1int - s2int) == mindiff \
          and (s1int < anss1 or (s1int == anss1 and s2int < anss2))):
        mindiff = abs(s1int - s2int)
        anss1 = s1int
        anss2 = s2int
        ss1 = list(s1)
        ss2 = list(s2)

  fout.write('Case #{}: '.format(i + 1))
  fout.write(''.join(ss1 + [' '] + ss2))
  fout.write('\n')

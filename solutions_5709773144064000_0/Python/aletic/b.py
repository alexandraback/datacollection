
n = int(raw_input())

def win(c,f,x):
  return c >= x


for test in xrange(1,n+1):
  c,f,x = map(float, raw_input().split())

  if x <= c:
    answer = x / 2.0
  else:
    farms = 0
    rate = 2.0
    cookies = c
    time = c / 2.0
    switch = c / f #time taken for net profit from buying a new farm
    while True:
      #print 't={}'.format(time)
      if cookies + switch * rate >= x:
        answer = time + (x - cookies) / rate
        break
        #don't need to buy a new farm
      else:
        rate +=f 
        #cookies -= c
        #cookies += switch * rate
        #time += switch
        time += c / rate
      #print time, cookies, rate
      if cookies >= x:
        answer = time
        break
   
  
  
  print 'Case #%d: %.7f' % (test, answer)
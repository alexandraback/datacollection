from __future__ import division
import sys

def function(string, str_to_search_for):
      count = 0
      for x in xrange(len(string) - len(str_to_search_for) + 1):
           if string[x:x+len(str_to_search_for)] == str_to_search_for:
                count += 1
      return count

t=int(input())
w=1
while t>0:
	t -= 1
	sys.stdout.write('Case #'+str(w)+': ')
	w+=1

	k, l, s = [int(a) for a in raw_input().split()]
	key = raw_input()
	wrd = raw_input()

	flag = 0
	x = [wrd[i:i+1] for i in xrange(0, len(wrd))]
	for a in x:
		if a not in key:
			flag = 1
			break
	if (flag == 1):
		print 0.0
		continue

	ans = 1
	for a in x:
		ans *= key.count(a)/len(key)

	a=int(s/len(wrd))
	b=function(wrd*a+wrd[0:s%len(wrd)], wrd)
	a = b
	print a-ans*a
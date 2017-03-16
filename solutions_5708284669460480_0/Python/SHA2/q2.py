'''
Created on May 10, 2015

@author: Incognito
'''

def IsApproximatelyEqual(x, y):
  """Returns True iff y is within relative or absolute 'epsilon' of x.

  By default, 'epsilon' is 1e-6.
  """
  epsilon=10**(-6)
  # Check absolute precision.
  if -epsilon <= x - y <= epsilon:
    return True

  # Is x or y too close to zero?
  if -epsilon <= x <= epsilon or -epsilon <= y <= epsilon:
    return False

  # Check relative precision.
  return (-epsilon <= (x - y) / x <= epsilon
       or -epsilon <= (x - y) / y <= epsilon)
  
T=int(raw_input())
for j in range(T):
    k,l,s=map(int,raw_input().split(" "))
    keyboard=raw_input()
    target=raw_input()
    result=0
#     print keyboard,target
    zero=False
    for c in target:
        if keyboard.find(c)==-1:
            result=0
            zero=True
            break
    if zero:
        print "Case #"+`j+1`+":",result
#         print "SSS"
        continue
    totalprob=1.0
    for c in target:
        prob=(keyboard.count(c)+0.0)/k
        totalprob*=prob
#     print totalprob
    max=s/l
    if l==1:
        max=s
    else:
        for i in xrange(1,l):
            temp=target[i:]
            if target.find(temp)==0:
                remain=s-l
                max=remain/i
                max+=1
                break
#     print "max: ",max
    if IsApproximatelyEqual(totalprob, 1):
        result=0.0
    if IsApproximatelyEqual(totalprob, 0):
        result=max+0.0
    else:
        result=(1-totalprob)*max
    print "Case #"+`j+1`+":",result
    
        
        
        
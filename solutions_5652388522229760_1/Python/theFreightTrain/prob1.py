def getLast(n):
    t = n
    digits = [0]*10
    digits = updateDigits(t,digits)
    while(sum(digits)<10):
        t += n
        digits = updateDigits(t,digits)
    return t
    
def updateDigits(t,digits):
    for i in range(len(str(t))):
        ind = int(str(t)[i])
        digits[ind] = max(digits[ind],1)
    return digits
    
t = int(input())
for i in range(1, t + 1):
  n = int(input())
  print("Case #{}: {}".format(i,'INSOMNIA' if n==0 else getLast(n)))
  


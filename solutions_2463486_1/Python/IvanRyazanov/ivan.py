import sys
sys.stdin  = open("numbers","r")
sys.stdout = open("small.out","w")
numbers = []
count = int(input())
for i in range(count):
  numbers.append(int(input()))

sys.stdin = open("C-large-1.in","r")
T = int(input())
for test in range(T):
  ans = 0
  a,b=map(int,input().split())
  for number in numbers:
    if number>=a and number<=b:
      ans = ans + 1
  print("Case #",test+1,": ",ans,sep='')

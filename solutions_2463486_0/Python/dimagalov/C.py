input = open(file = "input", mode = 'r')
output = open(file = "output", mode = 'w')
n = int(input.readline().rstrip())
'''A = []
for number in range(1, 10 ** 7 + 1):
    if str(number) == str(number)[::-1]:
        if str(number ** 2) == str(number ** 2)[::-1]:
            A.append(number ** 2)'''

A = [0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]


for t in range(n):
    a, b = list(map(int, input.readline().rstrip().split()))
    output.write("Case #" + str(t + 1) + ": ")
    left = 0
    while(left < len(A) and A[left] < a):
        left += 1
    right = len(A) - 1
    while(right > -1 and A[right] > b):
        right -= 1
    output.write(str(right - left + 1) + "\n") 

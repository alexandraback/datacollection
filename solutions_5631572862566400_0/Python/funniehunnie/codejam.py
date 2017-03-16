arr = []
numbers = []
def counter(var,last):
    count = 0
    final = last
    if var not in numbers:
        final = var
        numbers.append(var)
    else:
        return count, final
    next = arr[var]
    
    if next not in numbers[1:len(numbers)-2]:
        count += 1
    countNext = counter(next,final)
    count += countNext[0]
    final = countNext[1]
    return count, final
    
case = int(input().strip())
for i in range(case):
    n = int(input().strip()) #total num kids
    arr = list(map(int,input().strip().split()))
    arr.insert(0,0)
    total = 0
    for j in range(1, len(arr)):
        number,last = counter(j,0)
        if arr.count(last) > 1 and last == arr[arr[last]]:
            number += 1
        if number > total:
            total = number
        numbers = []
        
    
    print("Case #%i: %d" %(i+1, total))

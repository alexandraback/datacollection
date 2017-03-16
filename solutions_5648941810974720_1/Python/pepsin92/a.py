import numpy as np

def convert(s):
    return [s.count(x) for x in "EFGHINORSTUVWXZ"]

numbers = np.array([convert(x) for x in ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]])

t = int(input().strip())
for tc in range(1, t+1):
    line = convert(input().strip())
    res=[]
    for num, let in [[0, 14], [2, 12], [6, 13], [8, 2], [4, 10], [7, 8], [5, 1], [1, 6], [3, 7], [9, 4]]:
        res+=[num for _ in range(line[let])]
        line =np.subtract(line, np.multiply(numbers[num], line[let]))
    print("Case #{}: ".format(tc), end='')
    print(''.join(sorted([str(x) for x in res])))

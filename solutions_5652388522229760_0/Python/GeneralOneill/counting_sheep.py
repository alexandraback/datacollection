def asleep(l):
    for num in range(0,10):
        if num not in l:
            return False
    return True

def count(n):
    if n == 0:
        return "INSOMNIA"
    l = []
    curr = n
    for i in range(1, 101):
        for num in str(curr):
            if int(num) not in l:
                l.append(int(num))
        if(asleep(l)):
            return curr
        curr = i * n
    return "INSOMNIA"


cases = int(raw_input())
for case in range(cases):
	n = int(raw_input())
        val = count(n)
        print("Case #" + str(case+1) + ": " + str(val))

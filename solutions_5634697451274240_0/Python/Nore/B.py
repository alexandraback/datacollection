
def flips(pcks):
    i, j = 0, len(pcks) - 1
    reversed = False
    count = 0
    while i <= j:
        if not reversed:
            if pcks[j] == '+':
                j -= 1
            else:
                if pcks[i] == '+': count += 1
                while pcks[i] == '+': i += 1
                reversed = True
                count += 1
        else:
            if pcks[i] == '-':
                i += 1
            else:
                if pcks[j] == '-': count += 1
                while pcks[j] == '-': j -= 1
                reversed = False
                count += 1
    return count

n = int(input())
for i in range(n):
    print("Case #" + str(i+1) + ":", end = " ")
    print(flips(input().strip()))
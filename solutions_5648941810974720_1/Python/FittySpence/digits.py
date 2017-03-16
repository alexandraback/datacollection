f = open('C:\\Users\\djspence\\Downloads\\A-large.in', 'r')

def decrement(counts, string, q):
    for i in range(0, len(string)):
        counts[q[string[i]]] -= 1

tries = int(f.readline())
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
q = dict()
for i in range(0, 26):
    q[alphabet[i]] = i
    
counts = [0 for i in range(0, 26)]
nums = [0 for i in range(0, 10)]


for i in range(0, tries):
    st = f.readline().strip()
    for j in range(0, len(st)):
        counts[q[st[j]]] += 1
        
        
    while counts[25] > 0:
        decrement(counts, "ZERO", q)
        nums[0] += 1
        
    while counts[23] > 0:
        decrement(counts, "SIX", q)
        nums[6] += 1
        
    while counts[22] > 0:
        decrement(counts, "TWO", q)
        nums[2] += 1
        
    while counts[6] > 0:
        decrement(counts, "EIGHT", q)
        nums[8] += 1
        
    while counts[19] > 0:
        decrement(counts, "THREE", q)
        nums[3] += 1
        
    while counts[17] > 0:
        decrement(counts, "FOUR", q)
        nums[4] += 1
        
    while counts[5] > 0:
        decrement(counts, "FIVE", q)
        nums[5] += 1
        
    while counts[21] > 0:
        decrement(counts, "SEVEN", q)
        nums[7] += 1
        
    while counts[8] > 0:
        decrement(counts, "NINE", q)
        nums[9] += 1
        
    while counts[14] > 0:
        decrement(counts, "ONE", q)
        nums[1] += 1
        
    toPrint = "Case #" + str(i+1) + ": "
    for j in range(0, 10):
        while nums[j] > 0:
            nums[j] -= 1
            toPrint = toPrint + str(j)
            
    print(toPrint)
        
        

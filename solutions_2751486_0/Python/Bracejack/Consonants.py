cases = int(raw_input())
case = 1

vowels = set('aeiou')

while case <= cases:
    
    word, n = raw_input().split()
    n = int(n)
    length = len(word)
    count = 0
    current = list(word)
    currentCount = [False] * length
    done = False
    if n == 1:
        done = True
        c = 0
        for letter in current:
            if letter not in vowels:
                currentCount[c] = True
            c += 1
    count += currentCount.count(True)
    
    for i in range(length - 1):
        
        newCurrentCount = [False] * (len(currentCount) - 1)
        if not done:
            new = []
            for j in range(length - i - 1):
                new.append(current[j] + word[j + i + 1])
        if i + 2 == n:
            done = True
            c = 0
            for s in new:
                if set(s).intersection(vowels) == set():
                    newCurrentCount[c] = True
                c += 1
        
        for b in range(len(currentCount)):
            if currentCount[b]:
                if b < len(newCurrentCount):
                    newCurrentCount[b] = True
                if b > 0:
                    newCurrentCount[b - 1] = True
        currentCount = newCurrentCount
        if not done:
            current = new
        count += currentCount.count(True)
            
    
    
    print "Case #" + str(case) + ": " + str(count)
    case += 1
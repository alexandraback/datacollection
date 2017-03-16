def last_word(word):
    if len(word) < 1:
        return ""
    if len(word) == 1:
        return word
    a = word[0]
    sol = a
    for i in word[1:]:
        if i < sol[0]:
            sol = sol + i
        else:
            sol = i + sol
    return sol
            
    
    

    
n = int(raw_input())
for i in range(n):
    start = raw_input()
    word = last_word(start)
    print "Case #{0}: {1}".format(i+1, word)
    

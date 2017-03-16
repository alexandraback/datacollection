from collections import Counter

nums = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
        "SEVEN", "EIGHT", "NINE"]

def handle_digit(count, digit, letter):
    '''
    notice that this function changes the content of the counter count
    '''
    res = []
    while count.get(letter,0) > 0:
        res.append(str(digit))
        for d in nums[digit]:
            count[d] -= 1
    return res
    
def digits(s):  
    c = Counter(s)
    cur = []

    cur += handle_digit(c, 0, "Z") 
    cur += handle_digit(c, 2, "W") 
    cur += handle_digit(c, 4, "U")        
    cur += handle_digit(c, 6, "X") 
    cur += handle_digit(c, 8, "G")
    cur += handle_digit(c, 1, "O")
    cur += handle_digit(c, 3, "H")
    cur += handle_digit(c, 5, "F")
    cur += handle_digit(c, 7, "S")
    cur += handle_digit(c, 9, "E")

    cur.sort()
    return "".join(cur)


T = int(raw_input())
for t in xrange(1, T+1):
    s = raw_input()
    print "Case #%d: %s"%(t, digits(s))
    


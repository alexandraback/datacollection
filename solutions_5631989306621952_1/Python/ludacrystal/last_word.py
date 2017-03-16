#returns the last alphabetically sorted word
def get_word(s):
    if len(s) <= 0:
        return

    last_word = s[0]
    for i in range(1, len(s)):
        c = s[i]
        #if later, append to the front
        if ord(c) >= ord(last_word[0]):
            last_word = ''.join([c, last_word])
        #else, append to the back
        else:  
            last_word = ''.join([last_word, c])

    return last_word
#number of test cases
t = int(raw_input().strip())

#for each test case
for i in range(1, t + 1):
    s = raw_input().strip()
    result = get_word(s)
    print("Case #" + str(i) + ": " + result)


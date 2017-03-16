f = open("input.txt", 'r')
T = int(f.readline().strip())
for i in range (0, T):
    string = f.readline()
    result = ''
    last = '?'
    for char in string:
        if char >= last:
            result = char + result
        else:
            result = result + char
        last = result[0]
    print "Case #" + str(i+1) + ": " + result.strip()



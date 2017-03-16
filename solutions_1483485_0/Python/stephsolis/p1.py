def decrypt(string):
    _map = {" ":" ", "a":"y", "b":"h", "c":"e", "d":"s", "e":"o", "f":"c", "g":"v", "h":"x", "i":"d", "j":"u", "k":"i", "l":"g", "m":"l", "n":"b", "o":"k", "p":"r", "q":"z", "r":"t", "s":"n", "t":"w", "u":"j", "v":"p", "w":"f", "x":"m", "y":"a", "z":"q"}
    out = ""
    for c in string:
        out += _map[c]
    return out

file = open("in1.txt")

numCases = int(file.readline())
for i in range(1, numCases+1):
    currLine = file.readline().strip()
    print("Case #" + str(i) + ": " + decrypt(currLine))
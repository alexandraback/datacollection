ALPHA = "abcdefghijklmnopqrstuvwxyz"
MAP = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

data = open("speaking_in_tongues.in")
out = open("speaking_in_tongues.out","w")
cases = int(data.readline())

for case in range(cases):
    str1 = data.readline().strip()
    str2 = ""
    for char in str1:
        str2 += MAP[char]
    out.write("Case #%i: %s\n" %(case+1,str2))
 
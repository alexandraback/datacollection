# Speaking in Tongues

mapping = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'q': 'z', 'z': 'q'}

i = open("A-small-attempt2.in", "r")
o = open("A-small.out", "w")

T = int(i.readline())

for c in range(1, T + 1):
    line = i.readline().replace('\n','')

    result = ""
    for x in line:
        try:
            result += mapping[x]
        except:
            result += x

    o.write("Case #{0}: {1}\n".format(c, result))

i.close()
o.close()   
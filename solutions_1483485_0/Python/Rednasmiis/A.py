code = {'a': 'y', 'b': 'h', 'c': 'e', 'd': 's', 'e': 'o', 'f': 'c', 'g': 'v', 'h': 'x', 'i': 'd', 'j': 'u', 'k': 'i',
        'l': 'g', 'm': 'l', 'n': 'b', 'o': 'k', 'p': 'r', 'q': 'z', 'r': 't', 's': 'n', 't': 'w', 'u': 'j', 'v': 'p', 'w': 'f',
        'x': 'm', 'y': 'a', 'z': 'q'}

f = open("A-small-attempt0.in")
o = open("output-small.txt",'w')
n = int(f.readline())


for i in range(1,n+1):
    gibberish = f.readline().strip()
    sentence = ""
    for letter in gibberish:
        if letter == ' ':
            sentence += ' '
        else:
            sentence += code[letter]
    o.write("Case #"+str(i)+": "+sentence+"\n")

f.close()
o.close()

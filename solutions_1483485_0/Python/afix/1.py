mappings = {'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q', ' ': ' ', '\n': ''}
inp = file("input.txt", "r")
outp = file("output.txt", "w")
test_case = inp.readlines()
for i in range(1, int(test_case[0]) + 1):
    print >> outp, "Case #{0}: ".format(i) + ''.join([mappings[x] for x in test_case[i]])
outp.close()

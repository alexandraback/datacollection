# Google code jam 3
# dijkstra

# Observations:

# By associativity, if the product of the string = i*j*k and we can form i and k from the front and end respectively, the middle equals j.
# 1 ** 4 == i ** 4 == j ** 4 == k ** 4 == 1. Therefore, we can ignore repetitions in multiples of 4. 

# Algorithm:
# Find some substring at the beginning that multiplies to i
# Find some substring at the end that multiplies to k.
# Check that the whole product equals i*j*k = -1.

filename = 'C-small-attempt0.in'

mult = {("1","1"):"1",("1","i"):"i",("1","j"):"j",("1","k"):"k",
        ("i","1"):"i",("i","i"):"-1",("i","j"):"k",("i","k"):"-j",
        ("j","1"):"j",("j","i"):"-k",("j","j"):"-1",("j","k"):"i",
        ("k","1"):"k",("k","i"):"j",("k","j"):"-i",("k","k"):"-1",
        ("1","-1"):"-1",("1","-i"):"-i",("1","-j"):"-j",("1","-k"):"-k",
        ("i","-1"):"-i",("i","-i"):"1",("i","-j"):"-k",("i","-k"):"j",
        ("j","-1"):"-j",("j","-i"):"k",("j","-j"):"1",("j","-k"):"-i",
        ("k","-1"):"-k",("k","-i"):"-j",("k","-j"):"i",("k","-k"):"1",
        ("-1","1"):"-1",("-1","i"):"-i",("-1","j"):"-j",("-1","k"):"-k",
        ("-i","1"):"-i",("-i","i"):"1",("-i","j"):"-k",("-i","k"):"j",
        ("-j","1"):"-j",("-j","i"):"k",("-j","j"):"1",("-j","k"):"-i",
        ("-k","1"):"-k",("-k","i"):"-j",("-k","j"):"i",("-k","k"):"1",
        ("-1","-1"):"1",("-1","-i"):"i",("-1","-j"):"j",("-1","-k"):"k",
        ("-i","-1"):"i",("-i","-i"):"-1",("-i","-j"):"k",("-i","-k"):"-j",
        ("-j","-1"):"j",("-j","-i"):"-k",("-j","-j"):"-1",("-j","-k"):"i",
        ("-k","-1"):"k",("-k","-i"):"j",("-k","-j"):"-i",("-k","-k"):"-1", }  #auto-generated. I hope this is right.

def contains_ijk(st, x):
    """Returns whether the string contains a substring that multiplies to i, then one that multiplies to j, then one that multiplies to k
    s - a string containing only "ijk"
    x - an int, number of times s is repeated
    """

# make s contain (4 + x % 4) repeats of the string. 
    if x >= 8:
        s = st * (4 + x % 4)
    else:
        s = st * x

    # Find a substring that multiplies to i
    first_i = -1 #position of the first time that the string multiplies to i. 
    product = "1"
    for i, ch in enumerate(s):
        product = mult[product, ch]
        if product == "i":
            first_i = i
            break
    if product != 'i':
        return False

    # Find a substring that multiplies to k
    product = "1"
    for ch in s[:first_i:-1]:
        product = mult[ch, product]
        if product == "k":
            break
    if product != 'k':
        return False

    # Check that the product equals -1
    product = "1"
    for ch in st:
        product = mult[product, ch]
    power = "1"
    for i in range(x % 4):
        power = mult[power, product]
    if power == "-1":
        return True
    else:
        return False

if __name__ == '__main__':
    filein = open(filename)
    fileout = open(filename.split('.')[0] + '.out', 'w')
    
    t = int(filein.readline()) # num test cases
    for i in range(t):
        L, X = (int(i) for i in filein.readline().split())
        st = filein.readline().strip()

        if contains_ijk(st, X):
            fileout.write("Case #{}: YES\n".format(i + 1))
        else:
            fileout.write("Case #{}: NO\n".format(i + 1))
    
    fileout.close()
    print("done")

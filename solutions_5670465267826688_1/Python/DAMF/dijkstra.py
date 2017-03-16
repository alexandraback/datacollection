#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

multiplication_table = {
        1 : {1:1, 'i':'i', 'j':'j', 'k':'k', -1:-1, "-i":"-i", "-j":"-j", "-k":"-k"},
        "i" : {1:"i", "i":-1, 'j':'k', 'k':"-j", -1:"-i", "-i":1, "-j":"-k", "-k":"j"},
        "j" : {1:"j", "i":"-k", 'j':-1, 'k':"i", -1:"-j", "-i":"k", "-j":1, "-k":"-i"},
        "k" : {1:"k", "i":"j", 'j':"-i", 'k':-1, -1:"-k", "-i":"-j", "-j":"i", "-k":1},
        -1 : {1:-1, 'i':'-i', 'j':'-j', 'k':'-k', -1:1, "-i":"i", "-j":"j", "-k":"k"},
        "-i" : {1:"-i", "i":1, 'j':'-k', 'k':"j", -1:"i", "-i":-1, "-j":"k", "-k":"-j"},
        "-j" : {1:"-j", "i":"k", 'j':1, 'k':"-i", -1:"j", "-i":"-k", "-j":-1, "-k":"i"},
        "-k" : {1:"-k", "i":"-j", 'j':"i", 'k':1, -1:"k", "-i":"j", "-j":"-i", "-k":-1},
        }

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [L, X] = line.split()
    X = int(X)
    L = int(L)
    ijk_string = f.readline().strip()

    # Note that ijk = -1
    # So first, you want to check out that string**X = -1
    string_product = 1
    for ijk in ijk_string:
        string_product = multiplication_table[string_product][ijk]
    # 1 can't be raised to a power to get -1
    # Anything else can, but only if it is a power of 2
    has_hope = True
    if string_product == -1:
        if (X%2) == 0:
            has_hope = False
    elif string_product == 1:
        has_hope = False
    elif (X%4) != 2:
        has_hope = False

    #if not has_hope:
        #print(case_num+1, "Failed before looking for an i")
    if has_hope:
        # Then you want to walk in from the front until you get an i
        has_hope = False
        i_product = 1
        num_used_for_i = -1
        # Note that if you are going to find a copy of i, you are going to find it in the concatenation of the first four copies
        for i_pos in range(L*4):
            i_product = multiplication_table[i_product][ijk_string[i_pos%L]]
            if i_product == "i":
                num_used_for_i = i_pos+1
                has_hope = True
                break

    #if not has_hope:
        #print(case_num+1, "Failed to find a k")
    if has_hope:
        # and walk in from the back until you get a k
        has_hope = False
        k_product = 1
        num_used_for_k = -1
        reverse_string = ijk_string[::-1]
        for k_pos in range(L*4):
            k_product = multiplication_table[reverse_string[k_pos%L]][k_product]
            if k_product == "k":
                num_used_for_k = k_pos+1
                has_hope = True
                break

    #if not has_hope:
        #print(case_num+1, "Failed to find a k")
    answer = "NO"
    # If you haven't crossed, you win
    if has_hope and num_used_for_k + num_used_for_i < (L*X):
        answer = "YES"

    print "Case #" + str(case_num+1) + ":", answer


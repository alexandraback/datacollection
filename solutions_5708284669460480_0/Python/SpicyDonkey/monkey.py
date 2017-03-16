from math import *

fin = open('monkey.in','r')
fout = open('OUTPUTFILE.txt','w')

T = int((fin.readline()).strip())   # T is the number of test cases

for test in range(T):
    # Write the main program here for each test case
    # test = test number
    # result = the result for the test case
    
    linein = fin.readline().strip().split()
    K, L, S = int(linein[0]), int(linein[1]) , int(linein[2]);

    keyboard = fin.readline().strip();
    word = fin.readline().strip();

    repeat = L;
    for i in range(L):
        if i == 0:
            continue;
        if word[i:] == word[:(L-i)]:
            repeat = i;
            break;
    
    
    shortkey = '';
    for i in range(26):
        if (chr(ord('A')+i) in keyboard):
            shortkey += chr(ord('A')+i)

    minbanana = 1 + int((S - L)/repeat);

    for letter in word:
        if not(letter in shortkey):
            minbanana = 0;
    if (minbanana == 0):
        result = 0;
        output_str = 'Case #' + str(test+1) + ': ' + str(result) + '\n'
        fout.write(output_str)
        continue;
        
    Kshort = len(shortkey)
    keyfreq = [];
    for letter in shortkey:
        keyfreq += [keyboard.count(letter)]

    cumbanana = 0;
    for i in range(Kshort**S):
        num = i
        sentence = ''
        frequency = 1
        for j in range(S):
            sentence += shortkey[num%Kshort]
            frequency *= keyfreq[num%Kshort]
            num = int(num/Kshort)
        #sentence is possible from monkey
        thisbanana = 0;
        while (word in sentence):
            thisbanana += 1;
            sentence = sentence[(sentence.find(word) + repeat):];

        cumbanana += thisbanana*frequency;

    expbanana = cumbanana/(K**S);

    
    result = minbanana - expbanana;
    
    output_str = 'Case #' + str(test+1) + ': ' + str(result) + '\n'
    fout.write(output_str)
    
fin.close()
fout.close()

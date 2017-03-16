__author__ = 'Amir'

print 'Case #1:'
numComplete = 0
primes = [2 ,     3 ,     5 ,     7 ,    11 ,    13 ,    17  ,   19 ,    23  ,   29 ,
            31 ,    37 ,    41 ,    43 ,    47 ,    53 ,    59 ,    61 ,    67 ,    71 ,
            73  ,   79 ,    83 ,    89,     97 ,   101,    103   , 107,    109    ,113 ,
            127  ,  131 ,   137 ,   139,    149 ,   151 ,   157  ,  163 ,   167   , 173 ,
            179  ,  181 ,   191 ,   193,    197 ,   199  ,  211 ,   223  ,  227  ,  229 ,
            233  ,  239 ,   241 ,   251 ,   257 ,   263 ,   269    ,271   , 277 ,   281 ,
            283   , 293 ,   307 ,   311,    313 ,   317  ,  331   , 337    ,347   , 349 ,
            353   , 359 ,   367 ,   373 ,   379 ,   383  ,  389  ,  397,    401  ,  409 ,
            419  ,  421 ,   431 ,   433 ,   439 ,   443  ,  449 ,   457 ,   461 ,   463 ,
            467  ,  479 ,   487 ,   491 ,   499 ,   503  ,  509,    521  ,  523 ,   541 ]

for k in range(2,29):
    for l in range(k+1,29):
        for p in range(l+1,29):
            if (numComplete > 499):
                break
            test = 10000000000000000000000000000011
            #test = 1000000000000011
            test += pow(10,k ) + pow(10, l) + pow (10, p)
            strTest = str(test)
            counter = 0
            testBase = [0 for n in range(9)]
            devisors = [0 for n in range(9)]


            for base in range (2,11):
                for n in range(len(strTest)):
                    testBase[base-2] += int(  strTest[len(strTest) - n -1])*pow(base, n)

                for m in range (len(primes)):
                    if (testBase[base -2]%primes[m] == 0 ):
                        devisors[base -2] = primes[m]
                        counter += 1
                        break

            if (counter == 9):
                print strTest + " " + ' '.join(map(str, devisors))
                numComplete +=1





fhIn  = open('input_small',  'r')
fhOut = open('output', 'w') 

nCase = int(fhIn.readline())
for iCase in range(1, nCase+1):

    iNumber = int(fhIn.readline())

    # Judge insomnia
    if iNumber == 0:

        strResult = format('Case #%d: INSOMNIA\n' % iCase)
        #print(strResult)
        fhOut.write(strResult)
        continue

    # Search
    iMulti   = iNumber
    setDigit = set()
    while True:

        # Count digits
        setDigit.update(set(str(iMulti)))
        if len(setDigit) == 10:

            break

        iMulti = iMulti + iNumber

    strResult = format('Case #%d: %d\n' % (iCase, iMulti))
    #print(strResult)

    fhOut.write(strResult)




fhIn.close()
fhOut.close()

def convert_input(listState):

    stateLen = len(listState)

    convertedState = []
    for idxState in xrange(0, stateLen):

        if listState[idxState] == '+':

            convertedState.append(True)

        elif listState[idxState] == '-':

            convertedState.append(False)

    return convertedState


def find_first_diff(listState):

    stateLen = len(listState)

    for idxState in xrange(1, stateLen):

        if listState[idxState] != listState[idxState-1]:

            return idxState

    return stateLen


def flip_top(listState, flipNum):

    flippedState = list(listState)
    for idxState in xrange(0, flipNum):

        flippedState[idxState] = listState[flipNum-idxState-1]^True

    return flippedState


fhIn  = open('input_large',  'r')
fhOut = open('output', 'w') 

nCase = int(fhIn.readline())
for iCase in range(1, nCase+1):

    listState = convert_input(list(fhIn.readline()))
    stateLen  = len(listState)

    # Maneuver
    nManeuver = 0 # number of manueuvers
    while True:

        # Find the first different state
        idxDiff = find_first_diff(listState)
        #print(str(idxDiff))
        if (idxDiff == stateLen) & (listState[0] == True):

            # All positive states
            break

        listState = flip_top(listState, idxDiff)
        nManeuver = nManeuver + 1

        print(str(listState))

    
    strResult = format('Case #%d: %d\n' % (iCase, nManeuver))
    print(strResult)

    fhOut.write(strResult)



fhIn.close()
fhOut.close()

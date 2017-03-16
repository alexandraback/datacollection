# import section
import math
import tools.math
import sys

def solve(inputFile, output):
    # read case number
    T = int(inputFile.readline())

    # iterate on all cases
    for t in xrange(T):
        # read N, L and H
        values = inputFile.readline().split(' ')
        H = int(values[0])
        W = int(values[1])
        D = int(values[2])

        # get map
        room = [['' for h in xrange(H)] for w in xrange(W)]

        # get map
        for h in xrange(H):
            for w in range(W):
                c = inputFile.read(1)
                if (c == 'X'):
                    # store our position
                    Xx = w + 0.5
                    Yx = h + 0.5
                room[w][h] = c
            inputFile.readline()

        returningRays = 0
        debugMap = [[False for h in xrange(-D, D + 1)] for w in xrange(-D, D + 1)]

        # Solving small input (excuse me for the very ugly code but I was very angry when I wrote it (the small solution bit))
        # maximum number of needed room reflections
        maxNumRefX = int(D / (W - 2)) + 1;
        maxNumRefY = int(D / (H - 2)) + 1;

        # calculate bottom right reflections
        Rx = int(W - 1.5 - Xx);
        if (2 * Rx < D):
            returningRays = returningRays + 1
        Ry = int(H - 1.5 - Yx);
        if (2 * Ry < D):
            returningRays = returningRays + 1
        X0 = 0
        obstructionsMap = [[False for h in xrange(D + 1)] for w in xrange(D + 1)]
        for x in xrange(1, maxNumRefX):
            X0 = X0 + 2 * Rx + 1
            Rx = W - 3 - Rx
            Y0 = 0
            for y in xrange(1, maxNumRefY):
                Y0 = Y0 + 2 * Ry + 1
                Ry = H - 3 - Ry
                if ((X0 * X0 + Y0 * Y0 <= D * D) and (not ((X0 == 0) and (Y0 == 0))) and (not obstructionsMap[X0][Y0])):
                    g = max(tools.math.GCD(X0, Y0), 1);
                    Dx = X0 / g;
                    Dy = Y0 / g;
                    Xj = X0;
                    Yj = Y0;
                    while ((Xj * Xj + Yj * Yj) <= D * D):
                        obstructionsMap[Xj][Yj]=True
                        Xj = Xj + Dx
                        Yj = Yj + Dy
                    debugMap[X0][Y0] = True;
                    returningRays = returningRays + 1
        # calculate top right reflections
        Rx = int(W - 1.5 - Xx);
        Ry = int(Yx - 1.5);
        if (2 * Ry < D):
            returningRays = returningRays + 1
        X0 = 0
        obstructionsMap = [[False for h in xrange(D + 1)] for w in xrange(D + 1)]
        for x in xrange(1, maxNumRefX):
            X0 = X0 + 2 * Rx + 1
            Rx = W - 3 - Rx
            Y0 = 0
            for y in xrange(1, maxNumRefY):
                Y0 = Y0 + 2 * Ry + 1
                Ry = H - 3 - Ry
                if ((X0 * X0 + Y0 * Y0 <= D * D) and (not ((X0 == 0) and (Y0 == 0))) and (not obstructionsMap[X0][Y0])):
                    g = max(tools.math.GCD(X0, Y0), 1);
                    Dx = X0 / g;
                    Dy = Y0 / g;
                    Xj = X0;
                    Yj = Y0;
                    while ((Xj * Xj + Yj * Yj) <= D * D):
                        obstructionsMap[Xj][Yj]=True
                        Xj = Xj + Dx
                        Yj = Yj + Dy
                    debugMap[X0][-Y0] = True;
                    returningRays = returningRays + 1
        # calculate bottom left reflections
        Rx = int(Xx - 1.5);
        if (2 * Rx < D):
            returningRays = returningRays + 1
        Ry = int(H - 1.5 - Yx);
        X0 = 0
        obstructionsMap = [[False for h in xrange(D + 1)] for w in xrange(D + 1)]
        for x in xrange(1, maxNumRefX):
            X0 = X0 + 2 * Rx + 1
            Rx = W - 3 - Rx
            Y0 = 0
            for y in xrange(1, maxNumRefY):
                Y0 = Y0 + 2 * Ry + 1
                Ry = H - 3 - Ry
                if ((X0 * X0 + Y0 * Y0 <= D * D) and (not ((X0 == 0) and (Y0 == 0))) and (not obstructionsMap[X0][Y0])):
                    g = max(tools.math.GCD(X0, Y0), 1);
                    Dx = X0 / g;
                    Dy = Y0 / g;
                    Xj = X0;
                    Yj = Y0;
                    while ((Xj * Xj + Yj * Yj) <= D * D):
                        obstructionsMap[Xj][Yj]=True
                        Xj = Xj + Dx
                        Yj = Yj + Dy
                    debugMap[-X0][Y0] = True;
                    returningRays = returningRays + 1
        # calculate bottom right reflections
        Rx = int(Xx - 1.5);
        Ry = int(Yx - 1.5);
        X0 = 0
        obstructionsMap = [[False for h in xrange(D + 1)] for w in xrange(D + 1)]
        for x in xrange(1, maxNumRefX):
            X0 = X0 + 2 * Rx + 1
            Rx = W - 3 - Rx
            Y0 = 0
            for y in xrange(1, maxNumRefY):
                Y0 = Y0 + 2 * Ry + 1
                Ry = H - 3 - Ry
                if ((X0 * X0 + Y0 * Y0 <= D * D) and (not ((X0 == 0) and (Y0 == 0))) and (not obstructionsMap[X0][Y0])):
                    g = max(tools.math.GCD(X0, Y0), 1);
                    Dx = X0 / g;
                    Dy = Y0 / g;
                    Xj = X0;
                    Yj = Y0;
                    while ((Xj * Xj + Yj * Yj) <= D * D):
                        obstructionsMap[Xj][Yj]=True
                        Xj = Xj + Dx
                        Yj = Yj + Dy
                    debugMap[-X0][-Y0] = True;
                    returningRays = returningRays + 1

        '''
        # this map holds the obstructed views
        obstructionsMap = [[False for h in xrange(-D, D + 1)] for w in xrange(-D, D + 1)]

        for Xi in xrange(- D, D + 1):
            for Yi in xrange(- D, D + 1):
                # check that the imaginary I is inside the foggy circle radius
                Dr = math.sqrt(float(Xi * Xi + Yi * Yi))
                # we account for epsilon differences since we are accumulating Deltas also no introspection allowed
                if ((Dr <= D + sys.float_info.epsilon) and (Dr > 0 + sys.float_info.epsilon) and (not obstructionsMap[Xi][Yi])):
                    # if so check this possible imaginary point

                    # shorten to make sure we never cross a line without knowing it
                    Df = 2 * max(max(abs(tools.math.LCM(Xi, Yi)), abs(Xi)), abs(Yi)) # LCM is enough but I'd rather not upload my math tools file
                    Dx0 = float(Xi) / Df
                    Dy0 = float(Yi) / Df
                    Dr0 = math.sqrt(float((Dx0 * Dx0) + (Dy0 * Dy0)))

                    # current Rays direction vector (changed inside the loop)
                    Dx = Dx0
                    Dy = Dy0

                    # now ray-trace from Xx, Yy in the direction Dx, Dy in Dx0, Dy0 each step towards Xr, Yr
                    Xr = Xx
                    Yr = Yx
                    ii = 0 # addition counter
                    while (Dr <= D + Df * Df *sys.float_info.epsilon):
                        Xr = Xr + Dx
                        Yr = Yr + Dy
                        ii = ii + 1
                        Dr = ii * Dr0

                        # check if we've reached our zero dimensional viewer (up to epsilon precision in Df calculation of around 1/Df size)
                        if ((Xr >= Xx - Df * Df * sys.float_info.epsilon) and (Xr <= Xx + Df * Df * sys.float_info.epsilon) and \
                            (Yr >= Yx - Df * Df * sys.float_info.epsilon) and (Yr <= Yx + Df * Df * sys.float_info.epsilon)):
                            if (obstructionsMap[int(round(ii * Dx0))][int(round(ii * Dy0))]):
                                break

                            debugMap[int(round(ii * Dx0))][int(round(ii * Dy0))] = True
                            returningRays = returningRays + 1;

                            # no seeing behind one's shoulder (in 2D) so mark all multiplications as invalid
                            jj = 1
                            while (jj * Dr <= D + Df * sys.float_info.epsilon):
                                obstructionsMap[int(round(jj * ii * Dx0))][int(round(jj * ii * Dy0))] = True
                                jj = jj + 1
                            break;

                        # handle mirror collisions
                        # check if we are passing to a different square (up to some epsilon accuracy)
                        if ((Xr - math.floor(Xr) <= Df * Df *sys.float_info.epsilon) or (math.ceil(Xr) - Xr <= Df * Df *sys.float_info.epsilon)):
                            if ((Yr - math.floor(Yr) <= Df * Df *sys.float_info.epsilon) or (math.ceil(Yr) - Yr <= Df * Df *sys.float_info.epsilon)):
                                if ((int(math.floor(Xr + Dx)) < 0) or (int(math.floor(Yr + Dy)) < 0) or (int(math.floor(Xr + Dx)) > W - 1) or (int(math.floor(Yr + Dy)) > H - 1)):
                                    break
                                # handle corners
                                if (room[int(math.floor(Xr + Dx))][int(math.floor(Yr + Dy))] == '#'):
                                    if (room[int(math.floor(Xr + Dx))][int(math.floor(Yr - Dy))] == '#'):
                                        if (room[int(math.floor(Xr - Dx))][int(math.floor(Yr + Dy))] == '#'):
                                            # x & y reflection
                                            Dx = -Dx
                                            Dy = -Dy
                                        else:
                                            # x reflection
                                            Dx = -Dx
                                    elif (room[int(math.floor(Xr - Dx))][int(math.floor(Yr + Dy))] == '#'):
                                        # y reflection
                                        Dy = -Dy
                                    else:
                                        # ray annihilated (no use throwing useless light this way)
                                        jj = 1
                                        while (jj * Dr <= D + Df * Df * sys.float_info.epsilon):
                                            obstructionsMap[int(round(jj * 2 * ii * Dx0))][int(round(jj * 2 * ii * Dy0))] = True
                                            jj = jj + 1
                                        break
                                # do nothing in the following 3 cases (ray passes between mirrors or near one mirror
#                                elif (map[int(math.floor(Xr + Dx))][int(math.floor(Yr - Dy))] == '#'):
#                                    if (map[int(math.floor(Xr - Dx))][int(math.floor(Yr + Dy))] == '#'):
#                                    else:
                            else:
                                # handle X reflections
                                if ((int(math.floor(Xr + Dx)) < 0) or (int(math.floor(Yr)) < 0) or (int(math.floor(Xr + Dx)) > W - 1) or (int(math.floor(Yr)) > H - 1)):
                                    break
                                if (room[int(math.floor(Xr + Dx))][int(math.floor(Yr))] == '#'):
                                    Dx = -Dx
                        elif ((Yr - math.floor(Yr) <= Df * Df * sys.float_info.epsilon) or (math.ceil(Yr) - Yr <= Df * Df * sys.float_info.epsilon)):
                            # handle Y reflections
                            if ((int(math.floor(Xr)) < 0) or (int(math.floor(Yr + Dy)) < 0) or (int(math.floor(Xr)) > W - 1) or (int(math.floor(Yr + Dy)) > H - 1)):
                                break
                            if (room[int(math.floor(Xr))][int(math.floor(Yr + Dy))] == '#'):
                                Dy = -Dy
        '''

        # output case result
        # 4 debug
        for Yi in xrange(- D, D + 1):
            S = ""
            for Xi in xrange(- D, D + 1):
                if (debugMap[Xi][Yi]):
                    S = S + '1'
                else:
                    S = S + '0'
            print(S)
        
        outputLine = 'Case #' + str(t + 1) + ": " + str(returningRays) + '\n'
        output.write(outputLine)
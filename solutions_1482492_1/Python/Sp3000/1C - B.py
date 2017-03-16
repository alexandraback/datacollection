infile = open("B-large.in", "rU")
outfile = open("output.txt", "w")
linenum = 0
case = 1
firstline = True

def dist(v, a, t):
    return v*t + 0.5*a*t*t

for line in infile:
    if linenum != 0:
        if firstline:
            line = line.strip()
            listy = line.split(" ")
            D = float(listy[0])
            N = int(listy[1])
            A = int(listy[2])
            firstline = False
            othercar = []
            count = 0
        else:
            if count == N:
                outfile.write("Case #" + str(case)  + ":\n")
                firstline = True
                accel = []
                line = line.strip()
                listy = line.split(" ")
                for a in listy:
                    accel.append(float(a))
                if len(othercar) == 1:
                    if othercar[0][1] >= D:
                        for a in accel:
                            t = ((2*a*D)**0.5)/a
                            outfile.write(str(t) + "\n")
                    else:
                        print "HEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEELP"
                else:
                    for a in accel:
                        lastt = othercar[0][0]
                        lastx = othercar[0][1]
                        v = 0
                        x = 0
                        t = 0
                        for index in xrange(1, len(othercar)):
                            tdif = othercar[index][0] - lastt
                            xdif = othercar[index][1] - lastx
                            carspeed = xdif/tdif
    ##                        print v, a, tdif, xdif, dist(v, a, tdif)
    ##                        if (dist(v, a, tdif) + x > othercar[index][1]):                                
    ##                            carspeed = xdif/tdif
    ##                            t0 = (-(v - carspeed) + ((v - carspeed)**2 - 2*a*(x - lastx))**0.5)/a
    ##                            t += t0
    ##                            x0 = dist(v, a, t0)
    ##                            if x + x0 > D:
    ##                                t += ((-v) + (v**2 - 2*a*(x-D))**0.5)/a
    ##                                print t, a, 1
    ##                                break
    ##                            else:
    ##                                x += x0
    ##                                v = carspeed
    ##                                if x + (tdif-t0)*v > D:
    ##                                    t += (D-x)/v
    ##                                    print t, a, 2
    ##                                    break
    ##                                t += (tdif-t0)
    ##                                x += (tdif-t0)*v
    ##                        else:
    ##                            if D < dist(v, a, tdif) + x:
    ##                                t += ((-v) + (v**2 - 2*a*(x-D))**0.5)/a
    ##                                print t, a, 3
    ##                                break
    ##                            t += tdif
    ##                            x = dist(v, a, tdif) + x
    ##                            v += tdif*a
    ##                            print t, x, v, 102
                            if othercar[index][1] >= D:
                                if dist(v, a, tdif) + x > othercar[index][1]:
                                    #print "a"
                                    t0 = (-(v - carspeed) + ((v - carspeed)**2 - 2*a*(x - lastx))**0.5)/a
                                    x0 = dist(v, a, t0)
                                    if x + x0 >= D:
                                        t += ((-v) + (v**2 - 2*a*(x-D))**0.5)/a
                                        break
                                    else:
                                        t += t0
                                        x += x0
                                        v = carspeed
                                        t += (D-x)/v
                                        break                                    
                                else:
                                    #print "b"
                                    t += ((-v) + (v**2 - 2*a*(x-D))**0.5)/a
                                    break
                            else:
                                if dist (v, a, tdif) + x > othercar[index][1]:
                                    #print "c"
    ##                                t0 = (-(v - carspeed) + ((v - carspeed)**2 - 2*a*(x - lastx))**0.5)/a
    ##                                t += t0
    ##                                x += dist(v, a, t0)
                                    ##v = max(carspeed, (dist(v, a, t0) - v*t0)/(0.5*a*t))
                                    v = ((xdif/(0.5*a))**0.5)*a
                                    #print v
                                    ##t += (othercar[index][1] - x)/v
                                    t = othercar[index][0]
                                    x = othercar[index][1]
                                else:
                                    #print "d"
                                    t += tdif
                                    x += dist(v, a, tdif)
                                    v += a*tdif
                                    
                            lastt = othercar[index][0]
                            lastx = othercar[index][1]
                        #print t
                        outfile.write(str(t) + "\n")
                        
                #print D, othercar, accel
                print case
                case += 1
            else:
                line = line.strip()
                listy = line.split(" ")
                othercar.append([float(listy[0]), float(listy[1])])
            count += 1
            
    linenum += 1
outfile.close()

#!/usr/bin/env python
import sys
import numpy as np

infile=open(sys.argv[1],'r')

NumCases=int(infile.readline())

for iCase in xrange(NumCases):
    line = infile.readline()
    #print line,
    h,w,d=[int(i) for i in line.split() ]
    


    #print
    infile.readline()
    for iH in xrange(h-2):
        line=list(infile.readline().strip())
        #print line
        line.pop()
        line.pop(0)
        for iW,char in enumerate(line):
            if char=='X':
                coords=( 2*iH+1, 2*iW+1 )


    

    w=(w-2)*2
    h=(h-2)*2
    d=d*2
            
    nReflect=int(d/(np.sqrt(2.0)*min( h,w)))+2

    coords=np.array(coords)
    d2=d**2


    infile.readline()
    images=set()
    images.add( ( coords[0], coords[1] ) )
    images.add(  ( -coords[0], coords[1] ) )
    images.add( ( coords[0], -coords[1] ) )
    images.add( ( -coords[0], -coords[1] ) )
    #print images,
    oldimages=images
    for i in xrange(nReflect):
#        if i%nReflect/10==0:
            #print '\r',i,
            #sys.stdout.flush()
        newimages=set()
        for image in oldimages:
            newimages.add( (image[0]+2*h , image[1]) )
            newimages.add( (image[0]-2*h , image[1]) )
            newimages.add( (image[0],  (2*w) + image[1]) )
            newimages.add( (image[0], (-2*w) + image[1]) )
        images.update(newimages)
        oldimages=newimages

    #Screen images
    #print 'a',
    #sys.stdout.flush()
    im_list=[ np.array(im)-coords for im in images if 
              d2 >= sum((coords-np.array(im))**2) >0]
    im_list.sort(key=lambda im: sum((im)**2))
    crosses=[ np.array(( im[1],-im[0])) for im in im_list ]

    i=0


    while i<len(im_list):
#        if i%100==0:
            #print '\r',i,len(im_list),
            #sys.stdout.flush()
        vec=im_list[i]
        j=i+1
        while j<len(im_list):
            if np.dot( vec, crosses[j] )==0 and np.dot(vec,im_list[j])>0:
                im_list.pop(j)
                crosses.pop(j)

#            elif abs(dp)>=0.999999999 and dp>0:
#                im_list.pop(j)
#                normed.pop(j)
            else:
                j+=1
        i+=1
                    
    

#    nSee=0
#    for image in im_list:
#        if d2 +0.001>= sum((image)**2):
#            nSee+=1
        


    print 'Case #'+str(iCase+1)+': ',len(im_list)
    #sys.stdout.flush()
#    if iCase==1: break

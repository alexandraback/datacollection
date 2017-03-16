import math

def canMoveOver(myCarLocation,otherCarLocations):
    for each in otherCarLocations:
        if abs(myCarLocation-each)<=5:
            return False
    return True

def cruiseControl(cars):
    speed=0
    location=1
    lowestTime=193275109837501985
    passingTimes=[]
    for firstCar in range(0,len(cars)):
        for secondCar in range(0,len(cars)):
            car1=cars[firstCar]
            car2=cars[secondCar]
            if car1==car2:
                continue
            if abs(car1[location]-car2[location])<=5:
                continue
            if car1[location]>car2[location]:
                continue
            if car1[speed]>car2[speed]:
                currentPassingTime=(car2[location]-car1[location]-5)/float((car1[speed]-car2[speed]))
                possibleProblems=[]
                for thirdCar in range(0,len(cars)):
                    if thirdCar!= firstCar and thirdCar!=secondCar:
                        car3=cars[thirdCar]
                        possibleProblems.append(car3[location]+(car3[speed]*currentPassingTime))
                car1Location=car1[location]+(car1[speed]*currentPassingTime)
                car2Location=car2[location]+(car2[speed]*currentPassingTime)
                if not canMoveOver(car1Location,possibleProblems) and not canMoveOver(car2Location,possibleProblems):
                    if currentPassingTime<lowestTime:
                        lowestTime=currentPassingTime
                        continue
    if lowestTime==193275109837501985:
        return "Possible"
    else:
        return str(lowestTime)
                    
                    
                    
X=open("csm2.in")
z=open("output.txt","w")
case=0
currentline=X.readline()
currentline=X.readline()
while currentline:
    case+=1
    print case
    cars=int(currentline)
    myCars=[]
    while cars:
        cars-=1
        myCars.append(map(int,X.readline().rstrip().lstrip().split()[1:]))
    z.write("Case #"+str(case)+": "+cruiseControl(myCars)+"\n")
    currentline=X.readline()
z.close()


T = int(raw_input())
for i in range(T):
	(farmCost, cookiesPerSecPerFarm, winningNumCookies) = [float(j) for j in raw_input().split()]
	if farmCost>winningNumCookies:
		print("Case #"+`i+1`+": "+`winningNumCookies/2.0`)
		continue
	currentCookiesPerSec = 2.0;
	currentTimeSpent = 0;
	while farmCost/currentCookiesPerSec + winningNumCookies/(currentCookiesPerSec+cookiesPerSecPerFarm) < winningNumCookies/currentCookiesPerSec:
	      #print("Time after buying a farm")
	      #print(farmCost/currentCookiesPerSec + winningNumCookies/(currentCookiesPerSec+cookiesPerSecPerFarm))
	      #print("Time without buying a farm")
	      #print(winningNumCookies/currentCookiesPerSec)
	      currentTimeSpent += farmCost/currentCookiesPerSec
	      currentCookiesPerSec += cookiesPerSecPerFarm
	      #print(currentTimeSpent)
	currentTimeSpent += winningNumCookies/currentCookiesPerSec
	print("Case #"+`i+1`+": "+`currentTimeSpent`)
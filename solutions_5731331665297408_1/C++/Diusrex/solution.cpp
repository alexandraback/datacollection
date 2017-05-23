#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Traverse(int currentCity, const vector<vector<int> >& connectedTo, vector<bool>& travelledTo)
{
    travelledTo[currentCity] = true;
    
    for (vector<int>::const_iterator toTravelTo = connectedTo[currentCity].begin(); toTravelTo != connectedTo[currentCity].end(); ++toTravelTo)
    {
        if (!travelledTo[*toTravelTo])
            Traverse(*toTravelTo, connectedTo, travelledTo);
    }
}


bool CanReachAllLeft(int city, const vector<vector<int> >& connectedTo, vector<bool>& travelledTo, vector<string> & zips)
{
    travelledTo[city] = true;
    
    for (vector<int>::const_iterator toTravelTo = connectedTo[city].begin(); toTravelTo != connectedTo[city].end(); ++toTravelTo)
    {
        if (!travelledTo[*toTravelTo])
            Traverse(*toTravelTo, connectedTo, travelledTo);
    }
    
    for (int i = 0; i < connectedTo.size(); ++i)
    {
        if (!travelledTo[i])
        {
            return false;
        }
    }
    
    return true;
}


int main()
{
    int T, N, M;
    
    cin >> T;
    
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> N >> M;
        
        vector<string> zips(N);
        
        for (int i = 0; i < N; ++i)
            cin >> zips[i];
        
        vector<vector<int> > connectedTo(N);
        
        int x, y;
        
        for (int i = 0; i < M; ++i)
        {
            cin >> x >> y;
            connectedTo[x - 1].push_back(y - 1);
            connectedTo[y - 1].push_back(x - 1);
        }
        
        
        vector<int> currentPath;
        vector<bool> travelledTo(N, false);
        
        int bestZipPos(-1);
        
        // Start at lowest ID
        for (int i = 0; i < N; ++i)
        {
            if (bestZipPos == -1 || zips[i] < zips[bestZipPos])
                bestZipPos = i;
        }
        
        string zipPath = zips[bestZipPos];
        travelledTo[bestZipPos] = true;
        
        currentPath.push_back(bestZipPos);
        
        while (zipPath.size() < N * 5)
        {
            bestZipPos = -1;
            
            // Can always drop farther down the path
            vector<bool> canReachFromSelfOrLower = travelledTo;
            
            int highestPath(-1);
            // Want to find the best guy to travel to next. May want to go down the path
                // Want to prioritize staying near the top of the path though
            for (int i = 0; i < currentPath.size(); ++i)
            {
                if (CanReachAllLeft(currentPath[i], connectedTo, canReachFromSelfOrLower, zips))
                {
                    for (vector<int>::const_iterator toTravelTo = connectedTo[currentPath[i]].begin(); toTravelTo != connectedTo[currentPath[i]].end(); ++toTravelTo)
                    {
                        // Will prioritize higher up
                        if (!travelledTo[*toTravelTo] && (bestZipPos == -1 || zips[*toTravelTo] <= zips[bestZipPos]))
                        {
                            bestZipPos = *toTravelTo;
                            
                            highestPath = i;
                        }
                    }
                }
            }
            
            while (highestPath != currentPath.size() -1)
                currentPath.pop_back();
                
            zipPath += zips[bestZipPos];
            currentPath.push_back(bestZipPos);
            
            travelledTo[bestZipPos] = true;
        }
        
        cout << "Case #" << t << ": " << zipPath << '\n';
    }
    
    
}